#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            int sum = N * j + M * i - 2 * i * j;
            if (sum == K)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        
    }
    cout << "No" << endl;
 
    return 0;
    
}
