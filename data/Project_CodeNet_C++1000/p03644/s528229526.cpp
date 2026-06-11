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
	
  int n;
  cin>>n;
  if(n==1) {
  	cout<<1;
  	return 0;
  }
  for (int i = 0; i < n; ++i)
  {
  	 if((1<<i)>n){
  	 	cout<<(1<<(i-1));
  	 	return 0;
  	 }
  }
   return 0;
}
