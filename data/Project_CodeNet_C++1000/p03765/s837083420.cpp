#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    ll q,a,b,c,d;
    cin>>q;
    ll n=s.length(),m=t.length();
    ll x[1+n];
    ll y[1+m];
    x[0]=y[0]=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='A')x[i+1]=(x[i]+1)%3;
    	else x[i+1]=(x[i]+2)%3;
    }
    for(int i=0;i<m;i++){
    	if(t[i]=='A')y[i+1]=(y[i]+1)%3;
    	else y[i+1]=(y[i]+2)%3;
    }
    vector<int> v; 
    while(q--){
    	cin>>a>>b>>c>>d;
    	if((x[b]-x[a-1]-y[d]+y[c-1])%3==0)v.pb(1);
    	else v.pb(0);
    }
    for(auto& i:v)cout<<((i)?"YES":"NO") <<endl;
    return 0;
}
