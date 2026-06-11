#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int N,a,b,u = 1;
ll A[100010],C[100010],visited[100010] = {0};
bool judge = true;
vector<vector<int>> v(100010);

void dfs(int n){
	visited[n] = 1;
	ll T = 2*A[n],ma = 0,sum = 0;
	for(int i=0;i<v[n].size();i++){
		if(visited[v[n][i]]==0){
			dfs(v[n][i]);
			T -= C[v[n][i]];
			sum += C[v[n][i]];
			ma = max(C[v[n][i]],ma);
		}
	}
	if(v[n].size()==1) C[n] = A[n];
	else C[n] = T;
	if(v[n].size()>=2){
		ll L = sum - A[n];
		if(T<0 || L<0) judge = false;
		if(2*ma>sum){
			if(L>sum-ma) judge = false;
		}else{
			if(L>sum/2) judge = false;
		}
	}
	if(n==u && T!=0) judge = false;
}

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		C[i] = INT_MAX;
	}
	for(int i=0;i<N-1;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=N;i++){
		if(v[i].size()>=2) u = i;
	}
	dfs(u);
	if(N==2 && A[1]==A[2]) judge = true;
	else if(N==2) judge = false;
	cout << (judge? "YES" : "NO") << endl;
}