#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    int black = 0;
    for(int i = 0; i <= N; i++){
        black = i * M;
        for(int j = 0; j <= M; j++){
            black += (N - (2 * i));
            if(black == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
