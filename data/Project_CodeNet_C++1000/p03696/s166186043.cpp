#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N; cin >> N;
  string S, T; cin >> S;
  T = S;
  while (1){
    int n = T.size();
    if (n==0) break;

    bool check = true;
    rep(i,n-1){
      if (T.substr(i,2)=="()"){
        T.erase(i,2);
        check = false;
        break;
      }
    }
    if (check) break;
  }
  int l=0, r=0;
  rep(i,T.size()) {
    if (T[i]=='(') r++;
    else l++;
  }
  cout << string(l,'(') << S << string(r,')') << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}
