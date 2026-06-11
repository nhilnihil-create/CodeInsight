#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int n = 0; n <= N; n++)
    {
        for (int m = 0; m <= M; m++)
        {
            int val = M*n + N*m - 2*(n*m);
            if(val == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
        
    }
    
    cout << "No"<< endl;

    return 0;
}
