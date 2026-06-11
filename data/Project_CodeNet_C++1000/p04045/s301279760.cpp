/*     ####   ####  #               ####  #        ##   #    # #    # ###### #####
      #      #    # #              #      #       #  #  ##  ## ##  ## #      #    #
       ####  #    # #               ####  #      #    # # ## # # ## # #####  #    #
           # #  # # #                   # #      ###### #    # #    # #      #####
      #    # #   #  #              #    # #      #    # #    # #    # #      #   #
       ####   ### # ###### #######  ####  ###### #    # #    # #    # ###### #    #
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<pair<LL, LL> > VP;
 
 
#define For(in) for (LLi i = 0; i < (n); i++)
#define FOR(in) for(LLi i=1; i <= (n); i++)
#define pb push_back
#define sr(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end());
#define exit(); return 0;
#define no "NO"
#define yes "YES"
#define con continue;
 

 
 
int main()
{
	
	LL n,m,i,a;
	cin>>n>>m;
	bool neg[10] = {};
	for(i=0; i<m; i++)
	{
		cin>>a;
		neg[a] = true;
	}
	LL ans=n;
	while(true)
	{
		LL x = ans;
		bool check = false;
		while(x != 0)
		{
			auto u = x % 10;
			if(neg[u])
			{
				check = true;
				break;
			}
			x /= 10;
		}
		if(!check)
		{
			cout<<ans<<endl;
			return 0;
		}
		ans++;
	}

		
		
	
	


			
    exit()
 
 
}
