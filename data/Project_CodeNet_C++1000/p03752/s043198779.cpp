#include<bits/stdc++.h>
using namespace std;
#define INF 100000000000;

int main()
{
	int N,K;cin >> N >>K;
	long long ans=INF;
	vector<int> building(N),building_fix(N);
	for (int i=0;i<N;i++) cin >> building[i];
	for (int i=0;i<1<<N;i++)
	{
		for (int i=0;i<N;i++) building_fix[i]=building[i];
		long long now=0;
		vector<int> choice;
		for (int r=0;i>>r>0;r++)
		{
			if ((i>>r)&1) choice.push_back(r);
		}
		if (choice.size()!=K) continue;
		choice.insert(choice.begin(),0);
		for (int k=1;k<K+1;k++)
		{
			int height=building_fix[choice[k-1]];
			for (int l=choice[k-1];l<choice[k];l++)
			{
				height=max(height,building_fix[l]);
			}
			if (height>=building[choice[k]] && choice[k-1]!=choice[k]) 
			{
				now+=height-building[choice[k]]+1;
				building_fix[choice[k]]=height+1;
			}
			if (height>=building[choice[k]] && choice[k-1]==choice[k]) 
			{
				now+=height-building[choice[k]];
				building_fix[choice[k]]=height;
			}
			//cout << now << endl;
		}
		ans=min(ans,now);
	}
	cout << ans << endl;
	return 0;
}