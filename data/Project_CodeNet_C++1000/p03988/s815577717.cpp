#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define lli long long int
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define ve vector<lli>
#define vep vector<pair<lli,lli> >
#define pii pair<int,int>
#define pll pair<lli,lli>
#define fr(i,n) for(lli i=0;i<(n);i++)
#define F first
#define S second
#define PI 3.141592653589793238
using u64 = uint64_t;
//using u128 = __uint128_t;
long long int gcd(long long int a,long long int b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int bin(long int a[],long int low,long int high,long d,long day[])
{
	//cout<<low<<" "<<high<<" "<<d<<"\n";
	if(low>high)return -1;
	long mid=(low+high)/2;
	if(a[mid]>(a[low]+d)&&(a[mid-1]<=(a[low]+d)||day[mid-1])&&day[mid]==0)
		return mid;
	else if(a[mid]>(a[low]+d)&&day[mid]==0)
		return bin(a,low,mid-1,d,day);
	else
		return bin(a,mid+1,high,d-a[mid+1]+a[low],day);
}
long long power(long long a,long long b)
{
	//cout<<a<<" "<<b<<"\n";
	if(b==0)return 1;
	if(b%2==0)return (power(((a*a)),b/2));
	return (((a)*(power(((a*a)),b/2))));
}
/*int subtree(vector<int>v,int sub[],i,j)
{
	if(sub[i]>0)return sub[i];
	for(auto x:v[i])
	{
		if(x!=j)sub[i]+=subtree(v,sub,x,i);
	}
	return sub[i];
}*/
bool cmp(int a,int b)
{
	return a>b;
}	
bool sortbysecdesc(const pair<int,int> &a, 
                   const pair<int,int> &b) 
{ 
       return a.first>b.first; 
} 

u64 binpower(u64 base,u64 e,u64 m)
{
	u64 ans=1;
	base%=m;
	while(e)
	{
		if(e&1)
		{
			ans=ans*base%m;
		}
		base=base*base%m;
		e>>=1;
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	for(int X=1;X<=t;X++)
	{
		//cout<<"Case #"<<X<<": ";
		int n;
		cin>>n;
		int a[n],i,cnt[n+1]={0},k;
		fr(i,n){cin>>a[i]; cnt[a[i]]++;}
		sort(a,a+n);
		//if(n==1&&a[0])
		k=(a[n-1]+1)>>1;
		//sort(a,a+n);
		if(a[0]!=k){cout<<"Impossible\n"; continue;}
		if(a[n-1]%2==0&&cnt[a[0]]>1){cout<<"Impossible\n"; continue;}
		if(a[n-1]%2==1&&cnt[a[0]]!=2){cout<<"Impossible\n"; continue;}
		int ch=1;
		for(i=a[n-1];i>a[0];i--)
		{
			if(cnt[i]<2){ch=0; break;}
		}
		if(ch){cout<<"Possible\n"; continue;}
		else {cout<<"Impossible\n"; continue;}
	}
	return 0;
}