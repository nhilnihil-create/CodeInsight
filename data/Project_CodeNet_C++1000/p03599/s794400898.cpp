#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main(){cout<<fixed<<setprecision(10);
		   int a,b,c,d,e,f;
           cin>>a>>b>>c>>d>>e>>f;
           //全探索？
           int water=0,sugar=0;
           //mizu
           int ans_w=1,ans_s=0;
           rep(i,0,31){
            rep(j,0,32){
              sugar=0;
              water=100*a*i+100*b*j;
              //sugar
              rep(k,0,32){
                 rep(l,0,3002){
                       sugar=l*c+d*k;
                   if(water+sugar>f)break;
                   if(water*e<100*sugar)break;
                   if(ans_s*(water+sugar)<=sugar*(ans_w+ans_s)){
                         ans_s=sugar;
                          ans_w=water;
                 //    cout<<i<<j<<k<<l<<endl;
                      }
                 }
              }
            }
           }
           cout<<ans_w+ans_s<<" "<<ans_s<<endl;
          // cout<<double(ans_s*100/(ans_w+ans_s))<<endl;
          // cout<<double(934*100/2634)<<endl;
}