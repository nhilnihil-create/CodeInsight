#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   ll a,b,c;
   cin>>a>>b>>c;
   if(a==(b+c))
   {
       cout<<"Yes"<<endl;
   }
   else if(b==(a+c))
   {
       cout<<"Yes"<<endl;
   }
   else if(c==(a+b))
   {
       cout<<"Yes"<<endl;
   }
   else
   {
       cout<<"No"<<endl;
   }
   return 0;
}
