#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    // 順番によらない
    // 片側に寄せても結果は同じ
    // 2重ループで全探索できる
    for(int y=0;y<=N;y++){
        for(int x=0;x<=M;x++){
            if(K == (M*y - y*x + x*(N-y))){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}