#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
#define Sort(v) sort(all(v))
#define Reverse(v) reverse(all(v))
#define Rsort(v) sort(all(v),greater)
#define pub(v) push_back(v)
#define pob(v) pop_back(v)
typedef long long ll;
typedef vector<ll> vel;
typedef vector<vector<ll>> vel2d;
typedef string str;
typedef pair<ll,ll> pal;
typedef vector<str> ves;


int main() {
    ll Q,H,S,D,N,ans=0;
    cin>>Q>>H>>S>>D>>N;
    ll q=Q*8,h=H*4,s=S*2,d=D,Min=min(min(q,h),min(s,d));
    if(Min==d){
        ans+=D*(N/2);
        
        N%=2;
        Min=min(min(q,s),h);}
    if(Min==s){ans+=S*N;}
    if(Min==h){ans+=H*N*2;}
    if(Min==q){ans+=Q*N*4;}
    cout<<ans<<endl;
}
