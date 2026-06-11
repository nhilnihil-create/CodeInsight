#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
map<char,bool> mp;
int main(){
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<s.size();i++){
       if(!mp[s[i]])cnt++;
       mp[s[i]]=1;
  }
 if(cnt==2){
     cout<<"Second"<<endl;
 }
 else{
     if(s.size()%2==1){
         if(s[0]==s[s.size()-1])cout<<"Second"<<endl;
         else cout<<"First"<<endl;
     }
     else{
         if(s[0]==s[s.size()-1])cout<<"First"<<endl;
         else cout<<"Second"<<endl;
     }
 }
}
