#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define f(i,a,n) for(ll i=a;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll isPrime(int n) 
{ 
	// Corner cases 
	if (n <= 1) 
		return 1; 
	if (n <= 3) 
		return 2; 

	// This is checked so that we can skip 
	// middle five numbers in below loop 
	if (n % 2 == 0 || n % 3 == 0) 
		return 1; 

	for (int i = 5; i * i <= n; i = i + 6) 
		if (n % i == 0 || n % (i + 2) == 0) 
			return 1; 

	return 2; 
} 

 
int main() 
{
    fast;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n,k=0;
        cin>>n;
        ll A[n],B[9]={0};
        for(ll i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]>=1 && A[i]<=399)
            {
                B[0]++;
            }
            if(A[i]>=400 && A[i]<=799)
            {
                B[1]++;
            }
            if(A[i]>=800 && A[i]<=1199)
            {
                B[2]++;
            }
            if(A[i]>=1200 && A[i]<=1599)
            {
                B[3]++;
            }
            if(A[i]>=1600 && A[i]<=1999)
            {
                B[4]++;
            }
            if(A[i]>=2000 && A[i]<=2399)
            {
                B[5]++;
            }
            if(A[i]>=2400 && A[i]<=2799)
            {
                B[6]++;
            }
            if(A[i]>=2800 && A[i]<=3199)
            {
                B[7]++;
            }
            if(A[i]>=3200)
            {
                B[8]++;
            }
        }
        for(ll i=0;i<8;i++)
        {
            if(B[i]>0)
            k++;
        }
        if(k==0)
        cout<<k+1<<" "<<k+B[8];
        else
        cout<<k<<" "<<k+B[8];
    }    
    return 0;
}
