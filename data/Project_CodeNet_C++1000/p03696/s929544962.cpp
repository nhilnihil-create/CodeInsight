#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[100];
  if(s[0] == '(') a[0] = 1;
  else a[0] = -1;
  int k = a[0];
  for(int i = 1; i < s.size(); i++){
    if(s[i] == '('){
      a[i] = a[i-1] + 1;
    }else{
      a[i] = a[i - 1] - 1;
      k = min(k, a[i]);
    }
  }
  while(k < 0){
    cout << '(';
    k++;
    a[s.size() - 1] ++;
  }
  cout << s;
  while(a[s.size() - 1] > 0){
    cout << ')';
    a[s.size()  - 1] --;
  }
  cout << endl;
}

