#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

ll mod(ll a)
{
	if(a<inf)return a;
	else 
	return a%inf;
}
 void test_cases()
{

ll n,m;
cin>>n>>m;
vector<string>a,b;
for(ll i=0;i<n;i++)
{
	string x;
	cin>>x;
	a.push_back(x);
}

for(ll i=0;i<m;i++)
{
	string x;
	cin>>x;
	b.push_back(x);
}


for(ll i=0;i<n;i++)
{
	for(ll j=0 ;j<n;j++)
	{
		
		if(j+m-1<n&&i+m-1<n)
		{
			bool yes=true;
			for(ll k=i;k<i+m;k++)
			{
				for(ll z=j;z<j+m;z++)
				{
					if(a[k][z]!=b[k-i][z-j])
					{
						yes=false;
						break;
					}
				}
				if(!yes)break;
			}
			
			if(yes)
			{
				cout<<"Yes";
				return;
			}
		}
	}
}

cout<<"No";

}


int main()
{
    fast;
  ll t;
 // cin>>t;
 t=1;
  while(t--)
  test_cases();

  	
}

		
	
	
	
	
