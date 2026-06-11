#include <bits/stdc++.h>
using namespace std;



int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> x(n);
  vector<long long> y(m);
  int md = 1e9+7;
  for (int i=0; i<n; i++) cin >> x[i];
  for (int i=0; i<m; i++) cin >> y[i];
  long long xsum=0, ysum=0;
  for (int k=0; k<n; k++){
    xsum += k*x[k] - (n-k-1)*x[k];
    xsum %= md;
  }
  for (int k=0; k<m; k++){
    ysum += k*y[k] - (m-k-1)*y[k];
    ysum %= md;
  }
  cout << xsum*ysum%md << endl;
}
