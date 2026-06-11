#include <iostream>
#include <map>
using namespace std;
#define ll long long
ll H,W,N,ans[10],y,x,dy[9]={-1,-1,-1,0,0,0,1,1,1},dx[9]={0,1,2,0,1,2,0,1,2};
map<ll,ll> chk;
int main()
{
	cin >> H >> W >> N;
	ans[0]=(H-2)*(W-2);
	
	for(int i=0; i<N; i++)
	{
		cin >> y >> x;
		map<ll,ll> c;	
	
		for(int j=0; j<9; j++)
		{
			ll py=y+dy[j],px=x+dx[j],p=(py-2)*(W-2)+(px-3);
			if(py<=H&&py>=2&&px<=W&&px>=3&&p<(H-2)*(W-2)&&!c[p])
			{
				c[p]=1;
				if(!chk[p])
				{
					chk[p]=1;
					ans[0]--,ans[1]++;
				}
				else if(chk[p]<=9)
				{
					ans[chk[p]]--;
					chk[p]++;
					ans[chk[p]]++;
				}
			}
		}
	}
	for(int i=0; i<10; i++)
	cout << ans[i] << "\n";
}