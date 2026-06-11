#include <bits/stdc++.h>
// atoi : atoi(str.c_str())
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int main(){
  long x;
  cin >> x;
  long sum = 0;
  for(long i=1;i<1e9;i++){
    sum += i;
    if(x <= sum){
      cout << i << endl;
      return 0;
    }
  }
}
