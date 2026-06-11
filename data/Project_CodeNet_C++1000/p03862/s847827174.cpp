//// Journey of Harry Singh from Diploma in Cse to Red Coder of India.///////////////////////////////////////////////////
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
int main(){


ll n,m;
cin>>n>>m;
ll a[n+1];
for(int i=1;i<=n;i++)
cin>>a[i];
ll count=0;
for(int i=2;i<=n;i++)
{
	ll p=a[i-1];
	ll c=a[i];
	if(c+p>m)
	{
		ll del=c+p-m;
		count+=del;
		if(del>=a[i]){
		del-=a[i],a[i]=0;}
		else if(del<a[i]){
		a[i]=a[i]-del,del=0;}
		
		
		if(del>0)
		{
			if(del>=a[i-1]){
		del-=a[i-1],a[i-1]=0;}
		else if(del<a[i-1]){
		a[i-1]=a[i-1]-del,del=0;}
		}
	}
}

cout<<count<<"\n";



}