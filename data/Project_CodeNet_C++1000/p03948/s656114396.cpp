#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,T;
    cin >> N >> T;
    int cnt = 0,mini = INF, maxd = 0;
    rep(i,0,N){
        int x;
        cin >> x;
        mini = min(mini, x);
        if(maxd < x - mini){
            maxd = x - mini;
            cnt = 1;
        }else if(maxd == x - mini)cnt++;
    }
    cout << cnt << endl;
}