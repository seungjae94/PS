#include <bits/stdc++.h>

using namespace std;

list<int> WaitingQueue;
list<int> BridgeQueue;
list<int> DestQueue;
    
int t = 0;
int MaxBridgeWeight = 0;
int BridgeWeight = 0;

bool CanMoveToBridge(int WaitingTruck)
{
    return 0 == BridgeQueue.back() && BridgeWeight + WaitingTruck <= MaxBridgeWeight;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int TruckCount = truck_weights.size();
    
    MaxBridgeWeight = weight;
    WaitingQueue = list<int>(truck_weights.begin(), truck_weights.end());
    BridgeQueue = list<int>(bridge_length, 0);
    
    while (true)
    {
        ++t;
        
        // Bridge -> Dest
        int BridgeTruck = BridgeQueue.front();
        
        if (BridgeTruck > 0)
        {
            DestQueue.push_back(BridgeTruck);
            
            if (DestQueue.size() == TruckCount)
            {
                break;
            }
        }
        
        BridgeQueue.pop_front();
        BridgeQueue.push_back(0);
        BridgeWeight -= BridgeTruck;
        
        // Waiting -> Bridge
        if (0 == WaitingQueue.size())
        {
            continue;
        }
        
        int WaitingTruck = WaitingQueue.front();

        if (true == CanMoveToBridge(WaitingTruck))
        {
            WaitingQueue.pop_front();
            BridgeQueue.pop_back();
            BridgeQueue.push_back(WaitingTruck);
            BridgeWeight += WaitingTruck; 
        }
    }
    
    return t;
}