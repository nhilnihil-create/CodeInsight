#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
bool isEven(string s){
	int n=SZ(s)/2;
	for (int i = 0; i <n ; ++i)
	{
		if(s[i]!=s[n+i]) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    string s;
    cin>>s;
    int n =SZ(s);	
    while(n>1){
    	s.erase(s.begin() + (n-1));
    	n=SZ(s);
    	
    	if(isEven(s)&&n%2==0) {
    		cout<<SZ(s);
    		return 0;
    	}
    	
    	
    }
  
   return 0;
}
