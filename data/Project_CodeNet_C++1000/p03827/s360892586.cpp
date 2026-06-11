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
#define r_rep(i, n) for(int i = n; i >= 0; i--)
#define ll long long int
#define pb push_back

const long long INF = 1LL << 60;

int main() {
  int N;
  string s;
  int m_num = 0, cnt = 0;
  cin >> N >> s;

  rep(i, N){
    if(s[i] == 'D') cnt--;
    if(s[i] == 'I') cnt++;
    m_num = max(cnt, m_num);
  }
  print(m_num);
}
