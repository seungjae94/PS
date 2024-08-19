#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> part_set {participant.begin(), participant.end()};
    
    for (string comp : completion)
    {
        auto iter = part_set.find(comp);
        if (part_set.end() != iter)
        {
            part_set.erase(iter);
        }
    }
    
    return *part_set.begin();
}