#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    long long sPos[N][2];
    long long cPos[M][2];
    long long maxDist = 500000000;

    for(int i=0; i<N; i++) cin >> sPos[i][0] >> sPos[i][1];
    for(int i=0; i<M; i++) cin >> cPos[i][0] >> cPos[i][1];

    for(int i=0; i<N; i++)
    {
        int num = 0;
        for(int j=0; j<M; j++)
        {
            long long temp = abs(sPos[i][0]-cPos[j][0]) + abs(sPos[i][1]-cPos[j][1]);
            if(temp < maxDist)
            {
                maxDist = temp;
                num = j+1;
            }
        }
        cout << num << endl;
        maxDist = 500000000;
    }

    return 0;
}