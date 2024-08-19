#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, list<string>> Info;
    
    // init
    for (vector<string>& cloth : clothes)
    {
        Info[cloth[1]].push_back(cloth[0]);
    }
    
    // calc
    int count = 1;
    for (pair<const string, list<string>>& Pair : Info)
    {
        count *= Pair.second.size() + 1;
    }

    return count - 1;
}