#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

pint p[200002];
int main(){
    ll w,h;
    cin>>w>>h;
    rep(i,w){
        cin>>p[i].first;
        p[i].second=0;
    }
    rep(i,h) {
        cin>>p[i+w].first;
        p[i+w].second=1;
    }
    sort(p,p+w+h);
    ll a=w+1,b=h+1;
    ll sum=0,cnt=0,cur=0;
    while(1){
        if(cnt>=(w+1)*(h+1)-1) break;
        int c=p[cur].first,f=p[cur].second;
        if(f==0){
            cnt+=b;--a;
            sum+=b*c;++cur;
        }
        else{
            cnt+=a;--b;
            sum+=a*c;++cur;
        }
    }
    cout<<sum<<endl;
    return 0;
}