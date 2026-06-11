#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    int q,a,b,c,d;
    string s,t;
    cin>>s>>t>>q;
    vec S(s.size()+1,0),T(t.size()+1,0);
    rep(i,s.size()) S[i+1]=S[i]+(s[i]=='A');
    rep(i,t.size()) T[i+1]=T[i]+(t[i]=='A');
    rep(i,q){
        cin>>a>>b>>c>>d;
        if(((S[b]-S[a-1])*2+a-b%3+2)%3==((T[d]-T[c-1])*2+c-d%3+2)%3) cout<<"YES\n";
        else cout<<"NO\n";
    }
}