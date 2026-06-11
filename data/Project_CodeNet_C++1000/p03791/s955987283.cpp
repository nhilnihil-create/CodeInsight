#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;

int N;
int X[111111];

signed main(){
    cin>>N;
    rep(i,N)cin>>X[i];

    int ans=1;
    int s=0;
    for(int i=0;i<N;i++){
        if(2*s+1<=X[i]){
            s++;
            continue;
        }
        ans=ans*(s+1)%mod;
    }
    for(int i=1;i<=s;i++)ans=ans*i%mod;
    cout<<ans<<endl;
    return 0;
}
