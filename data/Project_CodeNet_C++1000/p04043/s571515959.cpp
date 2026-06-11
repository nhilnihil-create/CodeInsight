 #include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>  
#include<set>
#include<iterator>
#include<list>
#include<utility>
#include<cstdlib>
#include<queue>
#include<stack>
#include<bitset>
//#include<bits/stdc++.h>
#define PI  2*acos(0.0)
#define pb push_back

       
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;



int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0), cout.tie(0);


ll a,b,c;
vector<int>v;
cin>>a>>b>>c;
v.push_back(a);
v.push_back(b);
v.push_back(c);
ll cnt5=0,cnt7=0;
for(int i=0;i<v.size();i++)
{
	if(v[i]==5)
	{
		cnt5++;
	}
	else
	{
		cnt7++;
	}
}


if(cnt5==2 && cnt7==1) cout<<"YES"<<"\n";
else cout<<"NO"<<"\n";









	
	
	return 0;
	
	
	       /***Israil Hosen
	            Computer Science & Engineering
	         University Of Rajshahi.
	         ***/
	
	
	
}