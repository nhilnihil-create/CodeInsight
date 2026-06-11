#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x = 0, n, fv = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		char s;
		cin >> s;
		if(s=='I') x++;
		else x--;
		fv = max(x, fv);
		//cout << x << " " << fv << endl;
	}
	cout << fv << endl;
	return 0;
}
