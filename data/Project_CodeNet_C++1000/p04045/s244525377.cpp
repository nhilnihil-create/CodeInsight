#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> flags(10, 0);
  rep(i, k){
    int num;
    cin >> num;
    flags[num] = 1;
  }
  while(true){
    string str = to_string(n);
    bool isok = true;
    rep(i, str.length()){
      if(flags[str[i]-'0'] == 1) isok = false;
    }
    if(isok){
      cout << n << endl;
      return 0;
    }
    n++;
  }
}
  
  