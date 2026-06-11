#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	ll ans1= 0, ans2 = 0;
	for(int i = 0; ; i++)
	{
		for(int j = 0; ; j++)
		{
			ll y = 100*(i)*a+j*100*b;
			if(y>=f) break;
			for(int k = 0; ; k++)
			{
				for(int h = 0; ; h++)
				{
					ll sugar = c*k+d*h;
					if(y+sugar<=f && (e*y/100)>=sugar)
					{
						if(ans1>0)
						{
							if(((double(100*sugar))/(sugar+y))>((double(100*ans2))/(ans1)))
							{
								ans1 = y+sugar; ans2 = sugar;
								if(sugar==(e*y/100))
								{
									cout<<ans1<<" "<<ans2<<endl;
									exit(0);
								}
							}
						}
						else
						{
							ans1 = y+sugar; ans2 = sugar;
							if(sugar==(e*y/100) && sugar!=0)
							{
								cout<<ans1<<" "<<ans2<<endl;
								exit(0);
							}
						}
					}
					if(sugar>(e*y/100))
						break;
				}
				if(k*c>(e*y/100))
					break;
			}
		}
		if(100*i*a>=f)
			break;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}