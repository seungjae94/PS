#include <bits/stdc++.h>

using namespace std;

int RoundUpDiv(int x, int y)
{
    return (x + y - 1) / y;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> Result;
    
    int Index = 0;
    int Size = progresses.size();
    
    int i = 0;
    while (i < Size)
    {
        int NeedTime = RoundUpDiv(100 - progresses[i], speeds[i]);
        
        for (int j = i; j < Size; ++j)
        {
            progresses[j] += speeds[j] * NeedTime;
        }
        
        int Count = 0;
        for (int j = i; j < Size; ++j)
        {
            if (progresses[j] < 100)
            {
                break;
            }
            
            ++i;
            ++Count;
        }
        
        Result.push_back(Count);
    }
    
    return Result;
}