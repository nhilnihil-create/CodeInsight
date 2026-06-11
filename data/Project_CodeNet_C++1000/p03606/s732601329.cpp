#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n,sum=0;	
	cin>>n;
	while(n--){
		int l,r;
		cin>>l>>r;
		sum+=(r+1)-l;
	}
	cout<<sum<<endl;
   return 0;
}
