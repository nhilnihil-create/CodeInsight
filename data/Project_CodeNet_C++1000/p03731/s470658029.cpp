#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=1; i<=(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N,T;
    cin>>N>>T;
    vi t(N);
    rep(i,N) cin>>t[i];
    ll ans=0;
    rep(i,N-1) ans+=min(t[i+1]-t[i],T);
    ans+=T;
    cout<<ans<<endl;
}