// ARC071_E
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

string s,t;
int sa[100009],ta[100009];

int q,a,b,c,d;

int main(){
    cin>>s>>t;
    rep(i,s.size())sa[i+1]=sa[i]+(s[i]=='A');
    rep(i,t.size())ta[i+1]=ta[i]+(t[i]=='A');
    
    cin>>q;
    while(q--){
        cin>>a>>b>>c>>d;
        cout<<((b-a+sa[b]-sa[a-1]-d+c-ta[d]+ta[c-1])%3?"NO\n":"YES\n");
    }
}