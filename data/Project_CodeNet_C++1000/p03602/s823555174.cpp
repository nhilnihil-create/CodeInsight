#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 40005;

int n, a[305][305];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	lint ret = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			bool rep = 0;
			for(int k=0; k<n; k++){
				if(a[i][j] > a[i][k] + a[k][j]){
					puts("-1");
					return 0;
				}
				if(i != k && k != j && a[i][j] == a[i][k] + a[k][j]){
					rep = 1;
				}
			}
			if(!rep) ret += a[i][j];
		}
	}
	cout << ret /2<< endl;
}

