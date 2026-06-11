#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a,b;
  cin>>a>>b;
  int one[] = {1,3,5,7,8,10,12};
  int two[] = {4,6,9,11};
  if(a == 2 || b == 2) {
    cout << "No" << endl;
    return 0;
  }
  if(find(begin(one), end(one), a) != end(one) && find(begin(one), end(one), b) != end(one)){
    cout << "Yes" << endl;
    return 0;
  }
  if(find(begin(two), end(two), a)!= end(two) && find(begin(two), end(two), b)!= end(two)) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
