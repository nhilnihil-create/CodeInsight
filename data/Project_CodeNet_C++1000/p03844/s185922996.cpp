	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main() {
		// #ifndef ONLINE_JUDGE
		// 	// for getting input from input.txt
		// 	freopen("input.txt", "r", stdin);
		// 	// for writing output to output.txt
		// 	freopen("output.txt", "w", stdout);
		// #endif
		ll a,b;
		char x;
	  cin>>a>>x>>b;
	  if(x == '+'){
	  cout<<a+b<<"\n";
	  }
	  else{
	  cout<<a-b<<"\n";
	  }
		return 0;
		}	