#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  map<int, int> a; rep(i,N) {int tmp; cin >> tmp; a[tmp]++;}
  string result = "No";
  if (a.size()==2) {
    auto it1 = a.begin(); int i1f = it1->first, i1s = it1->second;
    auto it2 = it1; it2++; int i2f = it2->first, i2s = it2->second;
    if (i2f-i1f==1) {
      if (i1s<=i1f && (N-i1s)/2+i1s>=i2f) result = "Yes";
    }
  }
  else if (a.size()==1) {
    int af = a.begin()->first;
    if (af==N-1||af<=N/2) result = "Yes";
  }
  cout << result << endl;
  return 0;
}