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
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  long long diff = b - a;
  for(int i = 0; i < n; ++i) {
  	long long l = -i * d + (n - i - 1) * c;
  	long long r = -i * c + (n - i - 1) * d;
  	// cout << l << ' ' << r << endl;
  	if(l <= diff && diff <= r) {
  		puts("YES");
  		return 0;
  	}
  }
  puts("NO");
	return 0;
}