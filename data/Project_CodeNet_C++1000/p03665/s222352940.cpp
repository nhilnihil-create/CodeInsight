#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> p;


int main(void){
	int n, p;
  cin >> n >> p;
  vector<int> odd, even;
  rep(i, n) {
    int x;
    cin >> x;
    if(x%2==0) even.push_back(x);
    else odd.push_back(x);
  }
  int n1 = odd.size(), n2 = even.size(); //奇数の数、偶数の数
  
  ll ans, select_odd = pow(2, n1)/2, select_even = pow(2, n2);
  
  
  if(p==0){
    ans = pow(2, n) - select_even * select_odd;
  }
  else{
    ans = select_even * select_odd;
  }
  cout << ans;
}
