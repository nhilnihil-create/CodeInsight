#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<long long>> comb(int n, int r) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main() {
    int n,p;
    cin >> n >> p;
    int a=0,b=0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x%2==0) a++;
        else b++;
    }

    ll s=1;
    for(int i = 0; i < a; i++) s *= 2;

    ll t=0;
    for(int i = p; i <= b; i+=2) {
        vector<vector<ll>> e=comb(b,i);
        ll w=e.at(b).at(i);
        t += w;
    }

    cout << s*t << endl;

    return 0;
}