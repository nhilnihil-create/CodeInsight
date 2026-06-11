#include <bits/stdc++.h>
using namespace std;
int main() {
	// #ifndef ONLINE_JUDGE
	// 	// for getting input from input.txt
	// 	freopen("input.txt", "r", stdin);
	// 	// for writing output to output.txt
	// 	freopen("output.txt", "w", stdout);
	// #endif
	
		int a,b,c;
		cin>>a>>b>>c;
		for (int i = 1; i < 1000000; ++i)
		{	
				int p = a*i;
				if(p%b == c){cout<< "YES"<<"\n"; return 0;}
		}
		cout<<"NO"<<"\n";
		return 0;	
	}	