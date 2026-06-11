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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
 int w,a,b;
 cin>>w>>a>>b;
 if(b>=(a+w))
 {
    cout<<(b-(a+w));
 }
 else if(b+w<=a)
    cout<<a-(b+w);
else
    cout<<0;

    return 0;
}






