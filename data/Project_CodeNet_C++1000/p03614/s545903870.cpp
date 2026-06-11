#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    int cnt = 0;
    rep(i,0,N-1){
        if(V[i] == i+1){
            swap(V[i], V[i+1]);
            cnt++;
        }
    }
    if(V[N-1] == N)cnt++;
    cout << cnt << endl;
}