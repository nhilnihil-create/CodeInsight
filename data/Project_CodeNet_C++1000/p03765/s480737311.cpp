#include<bits/stdc++.h>
#define maxn 100005
#define endl '\n'
using namespace std;
int sum[2][maxn];
int query(int *sum,int l,int r) {
	return sum[r] - sum[l-1];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s,t;
	cin >> s >> t;
	for(int i=0;i<(int)s.size();i++)
		sum[0][i+1] = (s[i] == 'A' ? 1 : 2) + sum[0][i];
	for(int i=0;i<(int)t.size();i++)
		sum[1][i+1] = (t[i] == 'A' ? 1 : 2) + sum[1][i];
	int q;
	cin >> q;
	while(q--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int x = query(sum[0],a,b) , y = query(sum[1],c,d);
		if(x % 3 == y % 3)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
