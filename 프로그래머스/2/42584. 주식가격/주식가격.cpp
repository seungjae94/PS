#include <bits/stdc++.h>

using namespace std;

struct PriceAndIndex
{
    int Price;
    int Index;
};

vector<int> solution(vector<int> prices) {
    vector<int> Times;
    
    for (int i = prices.size() - 1; i >= 0; --i)
    {
        Times.push_back(i);
    }
    
    // 4 3 2 1 0
    list<PriceAndIndex> Stack;
    for (int i = 0; i < prices.size(); ++i)
    {
        PriceAndIndex PAI = {prices[i], i};
        
        while (false == Stack.empty())
        {
            PriceAndIndex BackPAI = Stack.back();
            
            if (BackPAI.Price <= PAI.Price)
            {
                break;
            }
            
            // 주식이 떨어졌다.
            Times[BackPAI.Index] = PAI.Index - BackPAI.Index;
            Stack.pop_back();
        }
        
        Stack.push_back(PAI);
    }
    
    return Times;
}