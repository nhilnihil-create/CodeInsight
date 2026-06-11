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
int div(int n)
{  int c=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
          if(n/i==i)
            c++;
          else
            c+=2;
        }

    }

    
    return  c;
}
int func(int n)
{
    return (n*(n+1))/2;
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
   if(str.length()%2==0)
   {
      str=str.substr(0,str.length()-2);
      while(str.length())
      {
        string s,s1;
        s=str.substr(0,str.length()/2);
        s1=str.substr(str.length()/2,str.length()/2);
        if(s==s1)
        {
            cout<<str.length();
            return 0;
        }
        str=str.substr(0,str.length()-2);
      }
   }
   else
   {
      str=str.substr(0,str.length()-1);
      while(str.length())
      {
        string s,s1;
        s=str.substr(0,str.length()/2);
        s1=str.substr(str.length()/2,str.length()/2);
        if(s==s1)
        {
            cout<<str.length();
            return 0;
        }
        str=str.substr(0,str.length()-2);
      }
   }


 return 0;
}






