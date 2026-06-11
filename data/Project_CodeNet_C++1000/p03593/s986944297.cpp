#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
   int h, w;
   cin >> h >> w;
   vector<int>alp(26);
   vector<string>board(h);
   rep(i, 0, h)cin >> board[i];
   rep(i, 0, h){
       rep(j, 0, w){
           int p = board[i][j]-'a';
           alp[p]++;
       }
   }
   bool flag = true;
   if(h%2==0 && w%2==0){
       rep(i, 0, 26){
           if(alp[i]%4!=0)flag = false;
       }
   }else if(h%2==1 && w%2==0){
       int cnt = 0;
       rep(i, 0, 26){
           if(alp[i]%2==1)flag = false;
           else if(alp[i]%4==2)cnt++;
       }
       if(2*cnt>w)flag = false;
   }else if(h%2==0 && w%2==1){
       int cnt = 0;
       rep(i, 0, 26){
           if(alp[i]%2==1)flag = false;
           else if(alp[i]%4==2)cnt++;
       }
       if(2*cnt>h)flag = false;
   }else{
       int cnt1 = 0, cnt2 = 0;
       rep(i, 0, 26){
           if(alp[i]%4==1)cnt1++;
           else if(alp[i]%4==2)cnt2++;
       }
       if(cnt1!=1)flag = false;
       if(2*cnt2>(h-1+w-1))flag = false;
       //cout << "Pass" << endl;
   }
   if(flag)cout << "Yes" << endl;
   else cout << "No" << endl;
}