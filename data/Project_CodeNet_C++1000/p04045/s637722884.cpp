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

int n,k;
map<int,int> mp;
int x;
 
bool check(int x){
	while(x){
		int tmp=x%10;
		if(mp[tmp]){
			return false;
		}
		x/=10;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
  	cin>>n>>k;
  	 for(int i=1;i<=k;++i){
  	 	cin>>x;
  	 	mp[x]++;
  	 }

  	 for(int i=n;i<=1000000;++i){
  	 	if(check(i)){
  	 		cout<<i<<endl;
  	 		return 0;
  	 	}
  	 }



    return 0;
}