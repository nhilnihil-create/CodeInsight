// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,n,maxi=INF,f=0,mini=INF,sum=INF;
    string str,stra;
    cin>>stra;
    //vector<vector<ll>> v(tate,vector<ll> (yoko));
    //map<ll,ll> m;
    set<char> s;
    rep(i,stra.length())     s.insert(stra[i]);
    for(auto itr=s.begin();itr!=s.end();++itr){
      char key=*itr;
      //cout<<key<<endl;
      str=stra;
      ll po=str.length()-1;
      sum=0;
      c=1;
      while(c){
        rep(i,str.length()){
          if(str[i]!=key) f=1;
        }
        if(f==0){
          mini=min(mini,sum);
          c=0;
        }
        f=0;
        rep(i,str.length()-1) {
          if(str[i]==key||str[i+1]==key) str[i]=key;
        }
        str[po]=key;
        po--;
        sum++;
      }
    }
    cout<<mini<<endl;
    return 0;
}
