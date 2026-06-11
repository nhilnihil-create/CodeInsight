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
  string str,str2;
  cin>>str>>str2;
   if(str.length()>str2.length())
    cout<<"GREATER";
   else if(str.length()<str2.length())
    cout<<"LESS";
  else
  {     int i;
       for( i=0;i<str.length();i++)
       {
        if(str[i]>str2[i])
        {
            cout<<"GREATER";
            break;
        }
        else if(str[i]<str2[i])
        {
            cout<<"LESS";
            break;
        }
       }
       if(i==str.length())
        cout<<"EQUAL";
  }

    return 0;
}






