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
	    int n;
	    cin>>n;
	   	if(n == 1){ cout<<1; }
	   	else if(n>= 2 && n<=3){ cout<<2; }
	   	else if(n>=4 && n<=7){ cout<<4; }
	   	else if(n>=8 && n <=15){ cout<<8; }
	   	else if(n>=16 && n <=31){ cout<<16; }
	   	else if(n>=32 && n <=63){ cout<<32; }
	   	else if(n>=64 && n <=100){ cout<<64; }
	    return 0;
	  }
