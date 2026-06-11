#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint>PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int N;
bool use[1000050];

signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N;
    int sum=0;
    rep(i,0,N){
        sum+=i+1;
        use[i+1]=true; 
        if(sum>N){
            use[sum-N]=false;
            break;
        }
    }
    int cnt=1;
    rep(i,0,N){
        if(use[i+1])cout<<i+1<<endl;
        else{
            if(cnt)cnt--;
            else break;
        }
    }
    
    
    
    
    
    
    
    
    
    return 0;
}