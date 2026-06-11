#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
 
int a,b,c;
map<int,int> mp;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
  	cin>>a;
  	mp[a]++;
  	cin>>b;
  	mp[b]++;
  	cin>>c;
  	mp[c]++;
  	if(mp[5]==2 && mp[7]==1){
  		cout<<"YES"<<endl;
  	}
  	else cout<<"NO"<<endl;

    return 0;
}