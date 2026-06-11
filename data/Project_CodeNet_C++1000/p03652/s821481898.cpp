#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>    
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
// #define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int M = 1e9 + 7;
//__int128

signed main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  static int a[300][300];
  for(int i = 0; i < n; ++i) {
  	for(int j = 0; j < m; ++j) {
  		cin >> a[i][j];
  		--a[i][j];
  	}
  }  
  bitset<300> vis;
 	int res = n;
 	int T = m;
 	while(T--) {
 		std::vector<int> c(m, 0);
 		for(int i = 0; i < n; ++i) {
 			for(int j = 0; j < m; ++j) {
 				if(!vis[a[i][j]]) {
 					c[a[i][j]]++;		
 					break;
 				}
 			}
 		}
 		res = min(res, *max_element(all(c)));
 		vis[max_element(all(c)) - c.begin()] = 1;
 	}
 	cout << res << endl;
	return 0;
}