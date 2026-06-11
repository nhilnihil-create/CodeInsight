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
#define sz(x) ((int)(x).size())
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int N; cin >> N;
  vector<pair<int,int>> AB(N);
  rep(i,N) cin >> AB[i].first >> AB[i].second;
  sort(rall(AB));
  cout << AB[0].first+AB[0].second << endl;
  return 0;
}
