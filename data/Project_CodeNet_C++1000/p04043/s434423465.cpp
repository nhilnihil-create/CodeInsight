#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int a, b, c;
	//int count5 = 0, count7 = 0;
	map<int, int> M;
	cin >> a >> b >> c;
	M[a]++, M[b]++, M[c]++;
	if(M[5]==2 && M[7]==1){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}
