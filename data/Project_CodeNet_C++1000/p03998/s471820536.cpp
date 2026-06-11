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
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main() {
   string sa, sb, sc;
   cin >> sa >> sb >> sc;
   char s = sa[0];
   sa.erase(0, 1);
   int n = sa.size() + sb.size() + sc.size();
   rep(i, 0, n){
       if(s == 'a'){
           if(sa.size()==0){
               cout << "A" << endl;
               return 0;
           }
           s = sa[0];
           sa.erase(0, 1);
           //cout<< s << " " << endl;
           continue;
       }
       if(s == 'b'){
           if(sb.size()==0){
               cout << "B" << endl;
               return 0;
           }
           s = sb[0];
           sb.erase(0, 1);
           //cout<< "b" << " " << endl;
           continue;
       }
       if(s == 'c'){
           if(sc.size()==0){
               cout << "C" << endl;
               return 0;
           }
           s = sc[0];
           sc.erase(0, 1);
           //cout<< "c" << " " << endl;
           continue;
       }
   }
}