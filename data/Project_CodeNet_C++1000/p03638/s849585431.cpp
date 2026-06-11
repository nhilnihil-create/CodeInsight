#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int h,w;cin>>h>>w;
	int n;cin>>n;
	vector<int> a(n);
	vector<vector<int>> c(h,vector<int>(w));
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int x = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(a[x] == 0){
				x++;
			}
			c[i][j] = x + 1;
			a[x]--;
		}
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(i % 2 != 0){
				cout << c[i][w - 1 - j] << " ";
			}
			else{
				cout << c[i][j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}