#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    string s;cin>>s;
    reverse(all(s));

    int ex[26]={};
    vector<string>v;
    int l=0;
    rep(i,s.size()){

        ex[s[i]-'a']=1;
        if(count(ex,ex+26,1)==26){
            v.pb(s.substr(l,i-l+1));
            l=i+1;
            memset(ex,0,sizeof(ex));
        }
    }
    v.pb(s.substr(l,s.size()-l));

    for(int i=v.size()-1;i>=0;i--){
        char c;
        for(c='a';;c++)if(find(all(v[i]),c)==v[i].end())break;
        cout<<c;
        if(i==0)break;
        string &t=v[i-1];
        reverse(all(t));
        int k=find(all(t),c)-t.begin();
        t=t.substr(k+1,t.size()-k-1);
        reverse(all(t));
    }
    return 0;
}
