#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 9;
const int MAXN = 100005;
 
int n;
vector<int> gph[MAXN];
 
int f(int x, int p){
	int ans = 0;
	for(auto &i : gph[x]){
		if(i == p) continue;
		ans ^= f(i, x) + 1;
	}
	return ans;
}
 
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		gph[x].push_back(y);
		gph[y].push_back(x);
	}
	cout << (f(1, 0) ? "Alice" : "Bob");
}
