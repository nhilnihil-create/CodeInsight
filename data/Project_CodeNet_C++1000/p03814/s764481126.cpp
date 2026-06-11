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
  string str;
  cin>>str;
  int a=0;
  int b=0;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]=='A')
    {
        a=i;
        break;
    }
  }
  for(int i=str.length()-1;i>=0;i--)
  {
    if(str[i]=='Z')
    {
        b=i;
        break;
    }
  }
  cout<<b-a+1;


    return 0;
}






