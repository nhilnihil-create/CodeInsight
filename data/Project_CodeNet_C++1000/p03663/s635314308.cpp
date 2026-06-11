#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define mk make_pair
#define pb push_back
#define eps 1e-12
#define MAXN 200009
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int cnt=0;
	for(int test=1;test<=64;test++)
	{
		int low=0,high=9;
		if(test==1)
		{
			low=1;
		}
		while(low<high)
		{
			cnt++;
			//cout<<low<<" "<<high<<"\n";
			int mid=low+((high-low)/2);
			vector<int> vv=v;
			vv.pb(mid);
			while(vv.size()!=11)
			{
				vv.pb(9);
			}
			ll num=0;
			for(int i=0;i<vv.size();i++)
			{
				//cout<<vv[i]<<" ";
				num=(num*10ll)+vv[i];
			}
			//cout<<"\n";
			char ch;
			cout<<'?'<<' '<<num<<endl;
			cin>>ch;
			//cout<<ch<<"\n";
			if(ch=='Y')
			{
				high=mid;
			}
			else
			{
				low=mid+1;
			}
		}
		if(low==0)
		{
			cnt++;
			vector<int> vv=v;
			vv.pb(0);
			while(vv.size()!=11)
			{
				vv.pb(0);
			}
			ll num=0;
			for(int i=0;i<vv.size();i++)
			{
				num=(num*10ll)+vv[i];
			}
			char ch;
			cout<<'?'<<' '<<num<<endl;
			cin>>ch;
			if(ch=='Y')
			{
				break;
			}
			else
			{
				v.pb(low);
			}
		}
		else
		{
			v.pb(low);
		}
	}
	vector<int> v1;
	v1.pb(1);
	while(1)
	{
		if(v1.size()>10)
		{
			break;
		}
		cnt++;
		vector<int> vv=v1;
		ll num=0;
		for(int i=0;i<vv.size();i++)
		{
			num=(num*10ll)+vv[i];
		}
		char ch;
		cout<<'?'<<' '<<num<<endl;
		cin>>ch;
		if(ch=='Y')
		{
			v1.pb(0);
		}
		else
		{
			v1.pop_back();
			break;
		}
	}
	if(v1.size()>10)
	{
		v1.clear();
		v1.pb(9);
		while(1)
		{
			ll num=0;
			for(int i=0;i<v1.size();i++)
			{
				num=num*10;
				num+=v1[i];
			}
			char ch;
			cout<<'?'<<' '<<num<<endl;
			cin>>ch;
			if(ch=='Y')
			{
				break;
			}
			else
			{
				v1.pb(9);
			}
		}
		while(v.size()!=v1.size())
		{
			v.pb(0);
		}
		ll ans=0;
		for(int i=0;i<v.size();i++)
		{
			ans=(ans*10)+v[i];
		}
		cout<<'!'<<' '<<ans<<endl;
		return 0;	
	}
	int len=v1.size();
	while(v.size()!=len)
	{
		v.pb(0);
	}
	ll ans=0;
	for(int i=0;i<v.size();i++)
	{
		ans=(ans*10)+v[i];
	}
	cout<<'!'<<' '<<ans<<endl;
}