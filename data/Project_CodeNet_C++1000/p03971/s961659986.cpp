#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;

  int cnta=0, cntb=0;
  rep(i, n){
    if(s[i]=='a'){
      if(cnta<a+b){
        cnta++;
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    if(s[i]=='b'){
      if(cnta<a+b&&cntb<b){
        cnta++;
        cntb++;
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    if(s[i]=='c')cout << "No" << endl;
  }

  return 0;
}