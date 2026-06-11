#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int A,B,C,D,E,F,maxw{},ms{};
	cin>>A>>B>>C>>D>>E>>F;
	double m{};
	for(int a=0;a<F;a+=100*A)
	for(int b=0;a+b<F;b+=100*B)
	for(int c=0;c+a+b<=F;c+=C)
	{
		if(100.*c/(a+b+c)>E)break;
		
		for(int d=0;a+b+c+d<=F;d+=D)
		{
			double co=100*(c+d);
			co/=(double)(a+b+c+d);
			if(co>m)
			{
				if((c+d)>((a+b)/100)*E)break;
				//cout<<"Fuck\n";
				m=co;
				maxw=a+b+c+d;
				ms=c+d;
			}
		}
	}
	if(!maxw)maxw=100*A;
	cout<<maxw<<" "<<ms;
	
	
}