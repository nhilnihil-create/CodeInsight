#include <bits/stdc++.h>
using namespace std;
int main() {
	// #ifndef ONLINE_JUDGE
	// 	// for getting input from input.txt
	// 	freopen("input.txt", "r", stdin);
	// 	// for writing output to output.txt
	// 	freopen("output.txt", "w", stdout);
	// #endif
		string a,b,c;
		cin>>a>>b>>c;
		int d = a.length();
		int e = b.length();
		// int f = a.length();
		// cout<<a.at(d-1);

		if(a.at(d-1) == b.at(0) && b.at(e-1) == c.at(0)){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}

		return 0;	
	}	