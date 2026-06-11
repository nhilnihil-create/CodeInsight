#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;cin >> h >> w;
	string s;
	rep(i,h){
		rep(j,w){
			cin >> s;
			if(s=="snuke"){
				char c='A'+j;
				cout << c << i+1 << endl;
				return 0;
			}
		}
	}
}