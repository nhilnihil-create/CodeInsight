#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const ll INF = 1001001001;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int cnt = 0;
  int cntb = 0;
  rep(i,n){
    if(s[i]=='a'){
      if(cnt<a+b){
        cout << "Yes" << endl;
        cnt++;
      }
      else cout << "No" << endl;
    }
    if(s[i]=='b'){
      if((cnt<a+b)&&(cntb<b)){
        cout << "Yes" << endl;
        cnt++; cntb++;
      }
      else cout << "No" << endl;
    }
    if(s[i]=='c'){
      cout << "No" << endl;
    }
  }
}
