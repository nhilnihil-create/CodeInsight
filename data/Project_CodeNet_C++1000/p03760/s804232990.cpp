#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  string a, b;
  cin >> a >> b;

  rep(i, b.size()){
    cout << a[i] << b[i];
  }

  if(a.size()!=b.size()) cout << a[a.size()-1];
  cout << endl;
}
