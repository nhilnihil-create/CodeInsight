#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    string s,t;
    cin>>s;
    int ans=100;
    int Z=1;
    rep(i,s.size()) if(s[i]!=s[0]) Z=0;
    if(Z){
        cout<<0;
        return 0;
    }
    rep(i,s.size()){
        t=s;
        char a=s[i];
        int z=0,c=0;
        while(z==0){
            rep(i,t.size()) if(t[i+1]==a) t[i]=a;
            t.erase(t.size()-1);
            int x=1;
            rep(i,t.size()) if(t[i]!=a) x=0;
            if(x) z=1;
            c++;
        }
        ans=min(ans,c);
    }
    cout<<ans;
}