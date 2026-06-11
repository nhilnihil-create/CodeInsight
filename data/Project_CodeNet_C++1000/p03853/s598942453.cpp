#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

queue<char>q[3];


int main()
{
    fast;
  
 ll h,w;
 cin>>h>>w;
vector<string>v(h+1);

v[0]="\0";
 
 for(ll i=1;i<=h;i++)
 {

 	cin>>v[i];
 	

 }
 
 for(ll i=1;i<=2*h;i++)
 {
 	cout<<v[(i+1)/2]<<"\n";
 }
  	
}

		
	
	
	
	
