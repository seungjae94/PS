#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> tokenize(string s, string delimiter)
{
    vector<string> tokens;
    
    size_t start_pos = 0;
    size_t end_pos;
    size_t delim_size = delimiter.size();
    
    string token;
    
    while (true)
    {
        end_pos = s.find(delimiter, start_pos);
        
        if (end_pos == string::npos)
        {
            token = s.substr(start_pos);
            break;
        }
        
        token = s.substr(start_pos, end_pos - start_pos);
        start_pos = end_pos + delim_size;
        
        tokens.push_back(token);
    }
    
    tokens.push_back(token);
    return tokens;
}

string solution(string s) {
    vector<string> tokens = tokenize(s, " ");
    vector<int> vec;
    
    for (string token : tokens)
    {
        vec.push_back(stoi(token));
    }
    
    int min = *min_element(vec.begin(), vec.end());
    int max = *max_element(vec.begin(), vec.end());
    return to_string(min) + " " + to_string(max);
}