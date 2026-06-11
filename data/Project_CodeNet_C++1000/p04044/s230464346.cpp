#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef pair<ll,ll>pll;
const  ll MAX=100000000;
int main()
{

   vector<string>v;


   ll n,m;

   cin>>n>>m;


   while(n--)
   {

       string str;

       cin>>str;

       v.push_back(str);



   }

   sort(v.begin(),v.end());


   for(auto x:v)cout<<x;cout<<endl;


}

