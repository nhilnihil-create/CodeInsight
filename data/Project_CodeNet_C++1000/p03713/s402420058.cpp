#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    ll h,w;cin>>h>>w;
    ll ans=0;
    if(h%3==0||w%3==0){
        cout<<0<<endl;
        return 0;
    }
    else ans=min(h,w);
    rep2(i,1,h)ans=min(ans,max(i*w,max((h-i)*(w/2),(h-i)*(w-w/2)))-min(i*w,min((h-i)*(w/2),(h-i)*(w-w/2))));
    rep2(i,1,w)ans=min(ans,max(i*h,max((w-i)*(h/2),(w-i)*(h-h/2)))-min(i*h,min((w-i)*(h/2),(w-i)*(h-h/2))));
    cout<<ans<<endl;
}
