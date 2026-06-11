#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
	if(fopen("INPUT.txt","r"))
	{
	freopen ("INPUT.txt" , "r" , stdin);
	freopen ("OUTPUT.txt" , "w" , stdout);
	}
#endif  

	int a,b,c;
	cin>>a>>b>>c;
	map<pair<int,pair<int,int> >,int>mm;
	pair<int,pair<int,int> > s={a,{b,c}};
	int cnt=0;
	while (!mm[s])
	{
		if((s.first&1)||(s.second.first&1)||(s.second.second&1))
		{
			cout<<cnt<<endl;
			return 0;
		}
		pair<int,pair<int,int> > t;
		t.first=(s.second.first/2+s.second.second/2);
		t.second.first=(s.first/2+s.second.second/2);
		t.second.second=(s.second.first/2+s.first/2);
		mm[s]=1;
		s=t;
		cnt++;
	}
	cout<<-1;
	

}
