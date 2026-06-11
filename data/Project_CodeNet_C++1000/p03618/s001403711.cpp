#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define si(x) x.size()

char A[200005];
ll dp[200005];
map<char,ll> MP;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>A;
string S=A;
MP[A[0]]++;
rep1(i,si(S)){
    ll add=0;
    rep(k,26){
        char a='a'+k;
        if(A[i]!=a) add+=MP[a];
    }
    dp[i]=dp[i-1]+add;
    MP[A[i]]++;
}
cout<<dp[si(S)-1]+1<<endl;
 
}
    
