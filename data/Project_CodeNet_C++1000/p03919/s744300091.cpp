#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (2000000000)
#define MOD (1000000007)
#define PI (acos(-1))

int main(){
  int h,w;
  cin >> h >> w;
  string s;
  string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  rep(i,h){
    rep(j,w){
      cin >> s;
      if(s == "snuke"){
        cout << a[j] << i+1 << endl;
        return 0;
      }
    }
  }
}