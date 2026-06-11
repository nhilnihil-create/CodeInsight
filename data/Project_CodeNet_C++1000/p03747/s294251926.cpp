#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> ii;

int X[200005];
int dir[200005];
ii dest[200005];
int res[200005];

int n, L, T; 
void c(int &x){
	x %= L;
	if(x < 0) x += L;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> L >> T;
	for(int i = 1;i <= n;i++){
		cin >> X[i] >> dir[i];
		if(dir[i] == 1) dest[i].first = X[i] + T;
		else dest[i].first = X[i] - T;
		c(dest[i].first);
	}
	
	int offset = X[1];
	
	for(int i = 1;i <= n;i++) X[i] = X[i] - offset;
	
	int anchor = 0;
	
	for(int i = 1;i <= n;i++){
		if(dir[i] == dir[1]) continue;
		
		int low = 0;
		int high = 302345678;
		
		while(low != high - 1){
			int s = (low + high) / 2;
			
			int need = (s-1)*L;
			if(dir[1] == 1) need += X[i];
			else need += L - X[i];
			
			if(need < 2*T) low = s;
			else high = s; 
		}
		
		anchor += low;
	}
	
	anchor %= n;
	if(dir[1] == 1){
		dest[1].second = anchor+1;
	}
	else{
		dest[1].second = n-anchor+1;
		if(dest[1].second > n) dest[1].second -= n;
	}
	
	sort(dest+1,dest+1+n, [&](ii a, ii b){
		if(a.first != b.first) return a.first < b.first;
		if(dir[1] == 1) return a.second > b.second;
		else return a.second < b.second;
	});
	int pos = -1;
	for(int i = 1;i <= n;i++){
		if(dest[i].second != 0){
			pos = i; break;
		}
	}
	
	for(int i = 1;i < n;i++){
		int a = pos + i - 1;
		int b = pos + i;
		if(a > n) a -= n;
		if(b > n) b -= n;
		
		
		dest[b].second = dest[a].second + 1;
		if(dest[b].second > n) dest[b].second -= n;		
	}
	
	for(int i = 1;i <= n;i++){
		res[dest[i].second] = dest[i].first;
	}
	
	for(int i = 1;i <= n;i++){
		cout << res[i] << "\n";
	}
	
}


