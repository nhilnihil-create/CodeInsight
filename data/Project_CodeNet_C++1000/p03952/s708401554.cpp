#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double



////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,x;
signed main(){
  cin>>n>>x;
  if(x == 1 || x == 2*n-1){
    cout << "No" << endl;return 0;
  }
  cout << "Yes" << endl;
  if(n == 2){
    cout << 1 << endl << 2 << endl << 3 << endl;return 0;
  }
  queue<int> que;
  repd(i,1,2*n)if(!(x != 2 && x-2 <= i && i <= x+1) && !(x == 2 && 1 <= i && i <= 4))que.push(i);
  if(x != 2){
    int ind = 1;
    repd(i,1,2*n){
      if(n-1 <= i && i <= n+2){
        cout << x-2 << endl << x+1 << endl << x << endl << x-1 << endl;
        i += 3;
      }else{
        cout << que.front() << endl;que.pop();
      }
    }
  }if(x == 2){
    int ind = 1;
    repd(i,1,2*n){
      if(n-1 <= i && i <= n+2){
        cout << 3 << endl << 1 << endl << 2 << endl << 4 << endl;
        i += 3;
      }else{
        cout << que.front() << endl;que.pop();
      }
    }
  }
}
