#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool ispal(string a)
{
    long long int n=a.length();
    if(n==1)
        return true;
    else{
    int i=0,j;
    j=n-1;
    while(1)
    {
        if(a[i]!=a[j])
        {
            cout<<i<<" "<<j;
           return false;
        }
        i++,j--;
        if(i==j)
         {
        //     cout<<i<<" ";
             break;
        }
    }
    return true;
}}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 ll n;
 cin>>n;
 n*=2;
 int a[n];
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
 sort(a,a+n);
 ll ans=0;
 for(int i=0;i<n;i+=2)
 {
    ans+=a[i];
 }
 cout<<ans;
 }