#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n; string s;
    cin>>n>>s;
    s+=s[0];
    rep(p,0,2){
        rep(q,0,2){
            string ans;
            ans+=(p==0?'S':'W');
            ans+=(q==0?'S':'W');
            
            rep(i,2,n+2){
                if((s[i-1]=='o'&&ans[i-1]=='S') || (s[i-1]=='x'&&ans[i-1]=='W')) ans+=ans[i-2];
                else ans+=(ans[i-2]=='S' ? 'W' : 'S');
            }
            if(ans[0]!=ans[n]) continue;
            if(ans[1]!=ans[n+1]) continue;
            cout<<ans.substr(0,n)<<endl;
            return 0;
        }
    }
    
    cout<<-1<<endl;
}
