#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)



int main(){
    int n,t;cin>>n>>t;
    int a[n];rep(i,n)cin>>a[i];
    int cur=a[0];
    multiset<int> ms;
    rep(i,n-1){
        if(a[i]>a[i-1])continue;
        ms.insert(a[i-1]-cur);
        if(cur>a[i])cur=a[i];
    }
    ms.insert(a[n-1]-cur);
    int ans=1;
    auto it=ms.end();
    --it;
    int mval=(*it);
    while(it!=ms.begin()){
        if(*(--it)!=mval)break;
        else ++ans;
    }
    cout<<ans<<endl;
}
