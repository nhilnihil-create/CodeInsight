#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    if(a&1 || b&1 || c&1){
        cout<<0<<endl;
        return 0;
    }
    if(a==b && b==c){
        cout<<-1<<endl;
        return 0;
    }
    
    ll ans=0;
    set<tuple<long,long,long>>s;
    s.emplace(a,b,c);
    while(1){
        ll ah=a/2,bh=b/2,ch=c/2;
        a=bh+ch;b=ah+ch;c=ah+bh;
        if(s.count(make_tuple(a,b,c))){
            cout<<-1<<endl;
            return 0;
        }
        ans++;
        if(a%2==1 || b%2==1 || c%2==1){
            cout<<ans<<endl;
            return 0;
        }
    }
}