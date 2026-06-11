#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int count = 0;
	if(a%2 || b%2 || c%2){
		cout << count << endl;
	}
	else if(a==b && a==c){
		count = -1;
		cout << count << endl;
	}
	else{
		while(1){
			if(a%2 || b%2 || c%2) break;
			int t1 = (b+c)/2;
			int t2 = (a+c)/2;
			int t3 = (a+b)/2;
			a = t1;
			b = t2;
			c = t3;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
