#include <bits/stdc++.h>

using namespace std;

struct int2
{
    int X;
    int Y;
    
    vector<int2> GetNextPoints()
    {
        vector<int2> Points;
        Points.resize(4);
        
        for (int k = 0; k < 4; ++k)
        {
            Points[k] = {X + dx[k], Y + dy[k]};
        }
        
        return Points;
    }
    
    bool InRange(int _R, int _C)
    {
        return 0 <= X && X < _R && 0 <= Y && Y < _C;
    }
    
private:
    inline static int dx[4] = {1, -1, 0, 0};
    inline static int dy[4] = {0, 0, 1, -1};
};


int solution(vector<vector<int> > maps)
{
    int R = maps.size();
    int C = maps[0].size();
    
    vector<vector<int>> Weights;
    Weights.resize(R);
    for (vector<int>& Weights1D : Weights)
    {
        Weights1D = vector<int>(C, -1);
    }
    Weights[0][0] = 1;
    
    list<int2> Queue;
    Queue.push_back({0, 0});
    
    while (false == Queue.empty())
    {
        int2 Point = Queue.front();
        Queue.pop_front();
        
        for (int2& NextPoint : Point.GetNextPoints())
        {
            if (false == NextPoint.InRange(R, C))
            {
                continue;
            }
            
            if (0 == maps[NextPoint.X][NextPoint.Y])
            {
                continue;
            }
            
            if (-1 != Weights[NextPoint.X][NextPoint.Y])
            {
                continue;
            }
            
            Queue.push_back(NextPoint);
            Weights[NextPoint.X][NextPoint.Y] = Weights[Point.X][Point.Y] + 1;
        }
    }
    
    return Weights[R-1][C-1];
}