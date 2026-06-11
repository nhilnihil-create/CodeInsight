#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
map<int,int> num;
int ans;
set<int> a[100005];

void f(int s) {
    int sum = 0;
    for(auto itr = a[s].begin(); itr != a[s].end(); ++itr) {
      sum += num[*itr];
    }
    ans += sum / 2;
}

int main() {
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x % m].insert(x);
    num[x]++;
  }

  int l = 1;
  int r = m-1;

  while(l < r) {
    //   cout << l <<"  "<<r<<endl;
    int lsum = 0;
    int X = 0;
    int Y;
    for(auto itr = a[l].begin(); itr != a[l].end(); ++itr) {
      lsum += num[*itr];
      X += num[*itr] / 2;
    }
    Y = lsum - 2 * X;
    int rsum = 0;
    int XX = 0;
    int YY;
    for(auto itr = a[r].begin(); itr != a[r].end(); ++itr) {
      rsum += num[*itr];
      XX += num[*itr] / 2;
    }
    YY = rsum - 2 * XX;
    //  cout << lsum <<"  "<<rsum << endl;
    if(rsum < lsum) {
      int L = 0;
      int R = X;
      while(R - L > 1) {
	int mid = (L + R) / 2;
	if(2*mid >= rsum - Y) R = mid;
	else L = mid;
      }
      ans += rsum;
      if(rsum - Y <= 0) ans += X;
      else ans += X - R;
    }
    else {
      //  cout << XX << "  ji"<<YY << endl;
      int L = 0;
      int R = XX;
      while(R - L > 1) {
	int mid = (L + R) / 2;
	if(2*mid >= lsum - YY) R = mid;
	else L = mid;
      }
      ans += lsum;
      if(lsum - YY <= 0) ans += XX;
      else ans += XX - R;
    }
    l++;
    r--;
    // cout << "ans = "<<ans << endl;
  }
  if(l == r) {
    f(m/2);
  }
  f(0);

  cout << ans << endl;
      
}
    
