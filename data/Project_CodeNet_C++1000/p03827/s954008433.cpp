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
  int n;
  string str;
  int c=0;
  int cmax=0;
  cin>>n>>str;
  for(int i=0;i<n;i++)
  {
    if(str[i]=='D')
        c--;
    else
        c++;
    cmax=max(cmax,c);
  }
  cout<<cmax;

    return 0;
}






