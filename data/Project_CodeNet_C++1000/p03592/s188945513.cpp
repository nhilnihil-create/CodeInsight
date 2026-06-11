#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M;
    long k;
    cin >> N >> M >> k;    

    for (int y = 0; y <= N; y++)
    {
        for (int x = 0; x <= M; x++)
        {
            long black = y * M + x * N - x * y * 2;
            
            if (black == k)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
    return 0;
}