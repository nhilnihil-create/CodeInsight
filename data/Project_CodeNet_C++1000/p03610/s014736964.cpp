#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	
		     //  #ifndef ONLINE_JUDGE
	      //  // for getting input from input.txt
	      //  freopen("input.txt", "r", stdin);
	      //  // for writing output to output.txt
	      //  freopen("output.txt", "w", stdout);
	      // #endif
	string s;
	cin>>s;
	for (int i = 0; i < s.length(); ++i)
		{
			if(i%2 ==0){
				cout<<s[i];
			}
		}	
	return 0;
}