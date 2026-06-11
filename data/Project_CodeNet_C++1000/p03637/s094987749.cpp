#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

#define rep(i, n) for(ll i=0; i<n; ++i)

//--------------------

ll N;
ll A[100001];
ll c1, c2;

int main() {

  cin >> N;
  rep(i, N) {
    cin >> A[i];
    if(A[i]%4==0) ++c1;
    else if(A[i]%2==0) ++c2;
  }

  if(c1+(c2/2)>=N/2) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
