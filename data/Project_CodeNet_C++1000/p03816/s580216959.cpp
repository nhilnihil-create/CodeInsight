	#include<bits/stdc++.h>
	#define mod 1000000007
	#define ll long long int
	#define ar array
	#define mp make_pair
	using namespace std;

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		int n;
		cin>>n;
		int a[100001]={0};
		multiset< int,greater<int > >s;
		for(int i = 0 , j; i<n; i++)
		{
			cin>>j;
			a[j]++;
		}
		for(int i =1;i<100001; i++)
			if(a[i])
				s.insert(a[i]);
		sort(a, a+100001, greater<int>());
		int up = 0, down =0;
		for(int i = 0;i <100001;i++)
		{
			if(!a[i]) break;
			up = a[i]/3+a[i]%3;
			while(up>=3)
				up = up/3+ up%3;
			
			a[i]= up;
		}
		sort(a, a+100001, greater<int>());
		int y = count(a,a+100001,2);
		int h = count(a,a+100001,1);
		if(y&1)
			h--;
		cout<<y+h<<endl;
		return 0;
	}