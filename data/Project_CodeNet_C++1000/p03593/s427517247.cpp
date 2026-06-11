#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int h,w;
  cin >> h >> w;
  vint eng(26);
  rep(i,h) rep(j,w){
    char s;
    cin >> s;
    eng[s-'a']++;
  }
  int count2 = 0;
  int count4 = 0;
  int countodd = 0;
  rep(i,26){
    if(eng[i] % 4 == 0) count4++;
    else if(eng[i] % 2 == 0) count2++;
    else countodd++;
  }
  if(h % 2 == 0 && w % 2 == 1){
    if(countodd == 0 && count2 <= h/2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if(h % 2 == 0 && w % 2 == 0){
    if(count2 == 0 && countodd == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if(h % 2 == 1 && w % 2 == 1){
    if(countodd == 1 && count2 <= h/2 + w/2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if(h % 2 == 1 && w % 2 == 0){
    if(countodd == 0 && count2 <= w/2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}