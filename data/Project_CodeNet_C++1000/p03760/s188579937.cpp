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
  int k=0;
  int j=0;
  vector<char> v;
   for(int i=0;i<str.length()+str2.length();i++)
   {      if(i%2==0)
        {
          v.push_back(str[k]);
          k++;
        } 
        else
        {
            v.push_back(str2[j]);
            j++;
        }

   }

   for(auto x:v)
    cout<<x;
    return 0;
}






