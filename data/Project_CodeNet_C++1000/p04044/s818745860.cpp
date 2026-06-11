#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,l,i,j;
    cin>>n>>l;
    string temp,s[n];
    for(i=0;i<n;i++)cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
          {
              if(s[i].compare(s[j])>0)
              {
                  temp=s[i];
                  s[i]=s[j];
                  s[j]=temp;
              }
          }
          cout<<s[i];
    }
    cout<<endl;
}

