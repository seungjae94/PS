#include <bits/stdc++.h>

using namespace std;

void PrintVector(vector<int>& Vec)
{
    for (int n : Vec)
    {
        cout << n << " ";
    }
    cout << endl;
}

vector<int> PriorityCounts(10, 0);
list<int> Queue;

int solution(vector<int> priorities, int location) {
    for (int priority : priorities)
    {
        ++PriorityCounts[priority];
    }
    
    int MaxPriority = 9;
    while (PriorityCounts[MaxPriority] <= 0)
    {
        --MaxPriority;
    }
    
    for (int i = 0; i < priorities.size(); ++i)
    {
        Queue.push_back(i);
    }

    int ExecuteCount = 0;
    while (Queue.size() > 0)
    {
        int Process = Queue.front();
        Queue.pop_front();
        
        if (priorities[Process] == MaxPriority)
        {
            ++ExecuteCount;
            
            if (Process == location)
            {
                break;
            }
            
            --PriorityCounts[MaxPriority];
            
            while (PriorityCounts[MaxPriority] <= 0)
            {
                --MaxPriority;
            }
            
            continue;    
        }
        
        Queue.push_back(Process);   
    }
    
    return ExecuteCount; 
}