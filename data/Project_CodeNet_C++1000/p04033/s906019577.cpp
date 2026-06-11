		#include <bits/stdc++.h>
		  #define endl "\n"
		  #define ll long long int
		  #define mod 1000000007
		  #define inf 1000000000000000001;
		  using namespace std;
		  int main()
		  {
		    //  #ifndef ONLINE_JUDGE
		    //  // for getting input from input.txt
		    //  freopen("input.txt", "r", stdin);
		    //  // for writing output to output.txt
		    //  freopen("output.txt", "w", stdout);
		    // #endif
		    std::ios::sync_with_stdio(false);
		    cin.tie(NULL);
			ll a,b;
			cin>>a>>b;
			if(a>0 && b>0){ cout<<"Positive"; }
			else if(a <= 0 && b >= 0){ cout<<"Zero"; }
			else if(a >= 0 && b <= 0){ cout<<"Zero"; }
			else{
				if(abs(a-b)%2 != 0){
					cout<<"Positive";
				}
				else{
					cout<<"Negative";
				}
			}
		    return 0;
		  }
	