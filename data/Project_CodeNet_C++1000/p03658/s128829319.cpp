#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long int power(int a,int b)
{
    if(b==0)
        return 1;
    long long int k=power(a,b/2);
    if(b%2==0)
        return ((k%M)*(k%M))%M;
    else
        return ((k%M)*(k%M)*(a%M))%M;
}
long long int fact(long long int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return ((n%M)*(fact(n-1)%M))%M;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
   sort(arr,arr+n,greater<int>());
   long long int sum=0;
   for(int i=0;i<k;i++)
   {
    sum=sum+arr[i];
   }
   cout<<sum;



 return 0;
}






