#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	ll sum=0;
	while(1){
		sum += a;
		if(sum%b == c){
			cout << "YES" << endl;
			return 0;
		}
		if(sum%b == 0){
			cout << "NO" << endl;
			return 0;
		}
	}
}
