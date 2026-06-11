#include <bits/stdc++.h>
#define pb push_back
#define sz(a) int(a.size())
#define re return
#define all(a) a.begin(),a.end()
using namespace std;
int main()
{
	vector<int>k;
	int ans=0;
	int n;
	cin>>n;
	for (int i=0;i<2*n;i++){
		int y;
		cin>>y;
		k.pb(y);
	}
	sort(all(k));
	for (int i=0;i<2*n;i+=2){
		ans+=k[i];
	}
	cout<<ans;
	re 0;
}