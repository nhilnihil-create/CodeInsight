#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
#define f first
#define s second
int main()
{
	ll n;
	cin>>n;
	vector<int> s;
	while(n)
	{
		s.push_back(n%10);
		n=n/10;
	}
    reverse(s.begin(),s.end());
    ll sum=0;
    ll pow[11]={0};
    pow[0]=1;
    pow[1]=1;
    for(int i=2;i<11;i++)
    pow[i]=pow[i-1]*2;
    for(int i=0;i<s.size();i++)
    {
    	ll p=0;
    	for(int j=i;j<s.size();j++)
    	{
    		p=p*(ll)10+s[j];
    	//	cout<<p<<"\n";
    		sum+=p*pow[i]*pow[s.size()-j-1];
		}
	}
	cout<<sum<<endl;
	return 0;
}