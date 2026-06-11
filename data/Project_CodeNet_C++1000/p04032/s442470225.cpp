#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  string s; cin >> s;
  int n = (int)s.size();
  if(n==2 && s[0]==s[1]){
    cout << "1 2" << endl;
    return 0;
  }
  rep(i,n-2){
    string ss = s.substr(i,3);
    sort(all(ss));
    if(ss[0] == ss[1] || ss[1] == ss[2]){
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}
