#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N;
  string s;
  cin >> N >> s;
  vector<int> a(2,0);

  for(char c: s){
    if(c=='(') a[0]++;
    else {
      if(a[0] > 0) a[0]--;
      else a[1]++;
    }
  }
  rep(i, a[1]){
    cout << "(";
  }
  cout << s;
  rep(i, a[0]){
    cout << ")";
  }

  cout << endl;

}
