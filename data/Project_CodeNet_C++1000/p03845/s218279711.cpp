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
	int n,a[101],sum=0;
	cin>>n;
	for (int i = 1; i <= n; ++i)
		{
			cin>>a[i];
			sum+=a[i];
		}	
	int m,p,x;
	cin>>m;
	while(m--){
		cin>>p>>x;
		cout<<(sum-a[p])+x<<endl;
	}


   return 0;
}
