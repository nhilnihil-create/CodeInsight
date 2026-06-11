#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define MOD 1000000007
lli a[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;lli t=0ll,sum=0ll;
    cin>>n>>t;
    for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=1;i<n;++i)
	{
		sum+=min(t,a[i]-a[i-1]);
	}
	cout<<(sum+t)<<endl;
}
