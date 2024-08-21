#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string Word;
    int Dist;
};

bool CanConvert(string From, string To)
{
    int SameCount = 0;
    
    for (int i = 0; i < From.size(); ++i)
    {
        SameCount += static_cast<int>(From[i] == To[i]);
    }
    
    return SameCount == From.size() - 1;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    
    vector<int> Dists = vector<int>(words.size(), -1);
    Dists[words.size() - 1] = 0;
    
    list<Node> Queue;
    Queue.push_back({begin, 0});
    
    while (false == Queue.empty())
    {
        Node node = Queue.front();
        Queue.pop_front();
        
        for (int i = 0; i < words.size(); ++i)
        {
            if (false == CanConvert(node.Word, words[i]))
            {
                continue;
            }
            
            if (-1 != Dists[i])
            {
                continue;
            }
            
            Dists[i] = node.Dist + 1;
            Queue.push_back({words[i], Dists[i]});
        }
    }
    
    int TargetIndex = -1;
    for (int i = 0; i < words.size(); ++i)
    {
        if (target == words[i])
        {
            TargetIndex = i;
            break;
        }
    }
    
    if (-1 == TargetIndex)
    {
        return 0;
    }
    
    return -1 == Dists[TargetIndex] ? 0 : Dists[TargetIndex];
}