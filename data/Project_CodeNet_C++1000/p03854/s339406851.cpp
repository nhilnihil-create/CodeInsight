#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

string s;
bool dfs(int posi){
  if (posi == s.size()) return true;
  if (s.substr(posi, 5) == "dream"){
    if (dfs(posi+5)) return true;
  }
  if (s.substr(posi, 5) == "erase"){
    if (dfs(posi+5)) return true;
  }
  if (s.substr(posi, 6) == "eraser"){
    if (dfs(posi+6)) return true;
  }
  if (s.substr(posi, 7) == "dreamer"){
    if (dfs(posi+7)) return true;
  }
  return false;
}

int main(){
  cin >> s;
  if (dfs(0)) cout << "YES" << endl;
  else cout << "NO" <<endl;
}
