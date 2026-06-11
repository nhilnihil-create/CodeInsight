#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	 ll n ;
	 scanf("%lld",&n);
	 vector<ll>v;
	 ll in;
	 ll s = 0;
	 for(int i = 0; i < n ; i++)
	 {
	 	scanf("%lld",&in);
	 	v.push_back(in);
	 	s+= in;
	 }
	 ll pem = n*n+n;
	 pem=pem/2;
	 bool flag = 1;
	 
	 if(s%pem != 0)
	 {
	 	flag = 0;
	 }
	 else
	 pem = s/pem;
	 ll bed[100010];
	 bed[n-1] = v[0] - v[n-1];
	 for(int i = 0 ; i < n-1 ; i++)
	 {
	 	bed[i] = v[i+1] - v[i];
	 }
	 for(int i = 0 ; i < n ; i++)
	 {
	 	if(pem-bed[i] == 0) continue;
	 	if(pem-bed[i] < 0 || (pem-bed[i])%n !=0)
	 	{
	 		flag = 0;
//	 		cout<<pem<<endl;
		}
	 }
	 if(flag) cout<<"YES\n";
	 else
	 cout<<"NO\n";
}