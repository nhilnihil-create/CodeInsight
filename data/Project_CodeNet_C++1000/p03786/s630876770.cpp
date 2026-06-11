#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> vec;
  rep(i, n){
    int num;
    cin >> num;
    vec.push_back(num);
  }
  sort(all(vec));
  long long sum = 0;
  int res = 0;
  rep(i, n){
    if(sum*2 >= vec[i]) res++;
    else res = 1;
    sum += vec[i];
  }
  cout << res << endl;
  return 0;
}