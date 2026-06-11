#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100010];
long long a[100010],c=0,sum = 0;

long long dfs(int r,int p){
	if(g[r].size()==1){
		return a[r];
	}
	long long sum = 2*a[r];
	for(int i=0;i<g[r].size();i++){
		if(g[r][i]!=p){
			long long x = dfs(g[r][i],r);
			sum -= x;
			if(x>a[r]){
				c = 1;
			}
		}
	}
	if(sum<0 || sum>a[r]){
		c = 1;
	}
	return sum;
}

int main(){
	int i,n;
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==2){
		if(a[1]==a[2]){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		return 0;
	}
	for(i=0;i<n-1;i++){
		int c,b;
		cin >> c >> b;
		g[c].push_back(b);
		g[b].push_back(c);
	}
	for(i=1;i<=n;i++){
		if(g[i].size()==1){
			sum += a[i];
		}
	}
	if(sum%2==1){
		c = 1;
	}
	for(i=1;i<=n;i++){
		if(g[i].size()>1){
			if(dfs(i,0)){
				c = 1;
			}
			break;
		}
	}
	if(c){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
}
