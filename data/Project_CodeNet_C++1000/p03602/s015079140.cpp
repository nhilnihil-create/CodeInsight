#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

const int MAX_V = 310;
int d[MAX_V][MAX_V];
int flag[MAX_V][MAX_V];
int V;

int main() {
    int n;
    cin >> n;
    V = n;
    rep(i,n){
        rep(j,n){
            cin >> d[i][j];
        }
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                //d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if(d[i][j] > d[i][k]+d[k][j]){
                    cout << "-1" << endl;
                    return 0;
                }else if(d[i][j] == d[i][k]+d[k][j]){
                    if(k!=i && k!=j){
                        flag[i][j] = 1;
                    }
                    
                }
            }
        }
    }


    ll ans = 0;
    rep(i,n){
        rep(j,n){
            if(flag[i][j]==0){
                ans += d[i][j];
            }
        }
    }

    cout << ans/2 << endl;
    return 0;
}
 
 
