#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 998244353;//1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=1e6+5;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int mx=0;
	for(int i=0;i<n;i++) mx=max(mx,a[i]);
	multiset<int> s;
	int lowest=-1;
	int k=mx;
	if(mx%2==0)
	{	
		lowest=k/2+1;
		for(int i=k/2;i<=k;i++) s.insert(i);
		for(int i=k/2+1;i<=k;i++) s.insert(i);		 
	}
	else{
		lowest=(k+1)/2+1;
		for(int i=(k+1)/2;i<=k;i++) s.insert(i);
		for(int i=(k+1)/2;i<=k;i++) s.insert(i);	
	}
	set<int> left;
	for(int i=0;i<n;i++)
	{
		if(s.find(a[i])!=s.end())
		{
			s.erase(s.find(a[i]));
		}
		else left.insert(a[i]);
	}
	if(s.size()!=0)
	{
		cout<<"Impossible";
		return 0;
	}

	for(auto x:left)
	{
		if(x<lowest)
		{
			cout<<"Impossible";
			return 0;
		}
	}
	cout<<"Possible";
}
// Don't be afraid to fail. Be afraid not to try.
// "Become grindian instead of greendian" - aryanc403
// When you want to succeed as bad as you want to breathe, only then you’ll Be Successful!
// No Matter,How Fast You Are Driving If You Are Driving in a Wrong Direction You Will Never Reach Your Destination
// When failures hit you, you hit the failures back with Bounce Back!
// When you face failures, Don’t change your goal, Change your strategy!