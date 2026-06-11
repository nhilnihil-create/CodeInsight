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
#define MAX_N 200005
int flag[MAX_N];
vi G[MAX_N];

int main() {
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int x = 1;
    int ans[MAX_N] = {};
    int count = 0;
    while(true){
        flag[x] = 1;
        ans[count] = x;
        count++;
        int f = 0;
        rep(i,G[x].size()){
            if(flag[G[x][i]] == 0){
                x = G[x][i];
                f = 1;
                break;
            }
        }
        if(f==0){
            break;
        }
    }
    
    int ans2[MAX_N] = {};
    int count2 = 0;
    x = 1;
    while(true){
        flag[x] = 1;
        ans2[count2] = x;
        count2++; 
        int f = 0;
        rep(i,G[x].size()){
            if(flag[G[x][i]] == 0){
                x = G[x][i];
                f = 1;
                break;
            }
        }
        if(f==0){
            break;
        }
    }
    cout << count + count2 - 1 << endl;
    drep(i,count){
        cout << ans[i] << ' ';
    }
    srep(i,1,count2){
        cout << ans2[i] << ' ';
    }
    cout << endl;

    return 0;
}
 
 
