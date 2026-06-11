#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

using namespace std;



int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int> x;
	vector<int> y;
	rep(i,m+1)x.push_back(0);
	
	rep(i,n)
	{
		int a;
		cin>>a;
		y.push_back(a);
		x[a%m]++;
	}
	
	sort(y.begin(), y.end());
	
	
	int ans = 0;
	rep(i,m)
	{
		while(1)
		{
			bool ok = false;
			
			bool isHit = false;
			int a = i;
			int b = (m-i)%m;
			isHit |= (a!=b) && (x[a]>=1 && x[b]>=1);
			isHit |= (a==b) && (x[a]>=2);
			
			if(isHit)
			{
				ok = true;
				ans++;
				x[a]--;
				x[b]--;
			}
			
			if(!ok)break;
		}
	}
	
	
	rep(i,y.size()-1)
	{
		if(x[y[i]%m] < 2)continue;
		
		if(y[i]==y[i+1])
		{
			ans++;
			x[y[i]%m]-=2;
			i++;
		}
	}
	
	printf("%d\n",ans);
}