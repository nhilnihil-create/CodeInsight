#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
 
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<int, int> > vpi;
typedef vector<pair<ll, ll> > vpl;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
  cin >> h >> w;
  rep(i,h){
    rep(j,w){
      string s;
      cin >> s;
      if(s == "snuke"){
        cout << (char)('A'+j) << i+1 << endl;
      }
    }
  }
	return 0;
}
