#include <iostream>
#include <map>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 3e2+17;
LL dis[MAXN][MAXN],n;
bool can[MAXN][MAXN];
map<pair<int,int > ,int > mp;
LL func()
{
	LL ret = 0;
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j]) return -1;
				if(dis[i][j]==dis[i][k]+dis[k][j]&&k!=j&&k!=i)
				{
					// debug(i);
					// debug(j);
					// cerr<<endl;
					can[i][j] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(!can[i][j])
				ret += dis[i][j];
		}
	}
	return ret;
}
int main(int argc ,char const *argv[])
{
	#ifdef noob
	freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
	#endif
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			can[i][j] = false;
			cin>>dis[i][j];
		}
	}
	cout<<func()<<endl;
    return 0;
}