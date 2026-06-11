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
		int k,l;
	 	string s;
	 	cin>>s;
	 	for (int i = 0; i < s.size(); ++i)
	 	{
	 		if(s.at(i) == 'A'){
	 			k = i;
	 			break;
	 		}
	 	}

	 	for (int i = k+1; i < s.size(); ++i)
	 	{
	 		if(s.at(i) == 'Z' ){
	 			l = i;
	 		
	 		}
	 	}
	 	// cout<<l<<" "<<k;
	 	cout<<(l-k)+1<<"\n";
		return 0;
		}	