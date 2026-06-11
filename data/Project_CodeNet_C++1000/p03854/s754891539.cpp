#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

string q[4]={"dream", "dreamer", "erase", "eraser"};
string s;
int now=0;

bool check(int &x,char c){
  bool ok=true;
 if(c=='m'){
  rep(i,0,5){
    if(s[x]!=q[0][4-i])ok=false;
    //cout<<ok<<endl;
      x++;
  }
 }
  else if(c=='e'){
  rep(i,0,5){
    if(s[x]!=q[2][4-i])ok=false;
      x++;
  }
 }
  else if(c=='r'){
    if(s[x+2]=='s'){
      rep(i,0,6){
    if(s[x]!=q[3][5-i])ok=false;
      x++;
      }
    }
    else{
      rep(i,0,7){
    if(s[x]!=q[1][6-i])ok=false;
      x++;
       }
    }
 }
  else ok=false;
 return ok;
}


int main(){cout<<fixed<<setprecision(20);
		   //
           cin>>s;
           int n=s.size();
           reverse(all(s));
           while(now<n){
               if(!check(now,s[now])){
                cout<<"NO"<<endl;
                 return 0;
               }
            // cout<<now<<endl;
           }
           cout<<"YES"<<endl;
}