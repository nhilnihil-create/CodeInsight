#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int time = 0;
	time = min(b,d) - max(a,c);
	if(time < 0) time = 0;
	cout << time << endl;
}
