#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
   int n;cin>>n;
   vector<int> a(n);
   map<int,int> mp;
   rep(i,n){
       int a;cin>>a;
       mp[a]++;
   }
   int res=mp.size();
   int tmp=0;
   for(auto&p:mp){
       int buf=p.second;buf--;//消すべきカード枚数
       if(tmp>buf){
           tmp-=buf;
       }else{
           buf-=tmp;
           tmp=buf;
       }
   }
   if((tmp+1)%2==0)res--;
   cout<<res<<endl;
}