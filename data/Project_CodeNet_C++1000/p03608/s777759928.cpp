#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;
ll d[201][201];
struct edge{int from,to; ll cost;};

int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<edge> v(m);
    rep(i,n){
        rep(j,n){
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    vector<int> per(r);
    rep(i,r) {
        cin >> per[i];
        per[i]--;
    }
    rep(i,m){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        d[a-1][b-1] = c;
        d[b-1][a-1] = c;
    }
    for (int i= 0;i < n;i++){
        for (int j = 0;j < n;j++){
            for (int k = 0;k < n;k++){
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    ll ans = 1LL << 60;
    sort(per.begin(),per.end());
    do{
        ll tmp = 0;
        for (int i=0;i < r-1;i++){
            tmp += d[per[i]][per[i+1]];
        }
        ans = min(ans,tmp);

    }while(next_permutation(per.begin(),per.end()));
    cout << ans << endl;




    

    return 0;
}