#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int N, M, K; cin >> N >> M >> K;
    bool flag = false;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (M * i + (N - i) * j - i * j == K) flag = true;
        
        }
        
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
