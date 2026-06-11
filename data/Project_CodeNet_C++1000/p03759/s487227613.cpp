#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(b-a == c-b) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}