#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    unordered_set<int> pokemons;
    
    for (int num : nums)
    {
        pokemons.insert(num);
    }
    
    if (pokemons.size() >= n / 2)
    {
        return n / 2;
    }
    
    return pokemons.size();
}