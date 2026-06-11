#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const ll MOD=998244353,INF=1ll<<60;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
typedef pair<int,pint>P2;
typedef vector<vint>vvint;

int a,b,c,d,e,f,g,h;
int ans=0;

signed main() {
    IOS();
    cin>>a>>b>>c>>d>>e>>f>>g;
    if((a&&d%2&&e%2)||(a%2&&d&&e%2)||(a%2&&d%2&&e)){
        ans+=3;
        a--;
        d--;
        e--;
    }
    ans+=b+(a/2)*2+(d/2)*2+(e/2)*2;
    cout<<ans+(a%2&&d%2&&e%2)*3<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}