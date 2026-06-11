#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,M;
    cin >> N >> M;
    vector<int> V(N);
    rep(i,0,M){
        int a,b;
        cin >> a >> b;
        V[a-1]++;
        V[b-1]++;
    }
    rep(i,0,N){
        if(V[i] % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}