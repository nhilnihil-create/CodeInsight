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

int main() {
    int n,m;
    cin >> n >> m;
    int a[n][m];
    rep(i,n){
        rep(j,m){
            cin >> a[i][j];
        }
    }
    int flag[m+1] = {};

    int ans = 9999;

    rep(loop,m){
        int count[m+1] = {};
        rep(i,n){
            rep(j,m){
                if(flag[a[i][j]] == 0){
                    count[a[i][j]]++;
                    break;
                }
            }
        }
        int tmp = 0;
        int argi = 0;
        rep(i,m+1){
            if(tmp<count[i]){
                tmp = count[i];
                argi = i;
            }
        }
        ans = min(ans,tmp);
        flag[argi] = 1;
    }

    cout << ans << endl;
    return 0;
}
 
 
