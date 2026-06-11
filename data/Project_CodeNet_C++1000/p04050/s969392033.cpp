#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define mod 1000000007
int n,m,a[105];
int main(){
	cin >> n >> m;
	int x = 0;
	vector<int>vi,vi2;
	for(int i=1;i<=m;i++){
		cin >> a[i];
		x += (a[i]%2);
		if(a[i]%2==1) vi.pb(a[i]);
		else vi2.pb(a[i]);
	}
	int nxt = 1;
	for(int i=0;i<min(1,(int)vi.size());i++) a[nxt++] = vi[i];
	for(int i=0;i<vi2.size();i++) a[nxt++] = vi2[i];
	for(int i=1;i<vi.size();i++) a[nxt++] = vi[i];
	if(m==1){
	    if(n==1) puts("1\n1\n1");
		else cout << a[1] << endl << 2 << endl << a[1]-1 << endl << 1 << endl; return 0;
	}
	if(x >= 3){
		puts("Impossible"); return 0;
	}
	for(int i=1;i<=m;i++) cout << a[i] << (i==m?'\n':' ');
	if(x == 0){
		cout << m << endl;
		for(int i=1;i<=m;i++){
			int b;
			if(i==1) b = -1;
			else if(i==m) b = 1;
			else b = 0;
			cout << a[i]+b << endl;
		}
	}
	else if(x == 1){
		cout << m << endl;
		for(int i=1;i<=m;i++){
			int b;
			if(i==1) b = 1;
			else if(i==m) b = -1;
			else b = 0;
			cout << a[i]+b << endl;
		}
	}
	else{
		cout << (a[m]==1?m-1:m) << endl;
		for(int i=1;i<=m;i++){
			int b;
			if(i==1) b = 1;
			else if(i==m) b = -1;
			else b = 0;
			if(a[i]+b==0) break;
			cout << a[i]+b << endl;
		}
	}
}