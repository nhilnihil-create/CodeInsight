#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define run  ios_base::sync_with_stdio(false);cin.tie(NULL);
  //  mid =(l+r) >> 1 


  
int main()
 {

 ll n,i,m;
 cin>>n>>m;
 ll a[m],b[m],c=0;
 
 for(i=0;i<m;i++)
    cin>>a[i]>>b[i];
    
    ll h[100009];
    for(i=0;i<100009;i++)
        h[i]=1;

  ll  red[100009]={0};
      red[1]=1;
  
    for(i=0;i<m;i++)
    {
      if(red[a[i]]!=0)
      {
          if(h[a[i]]==1)
          {
             red[a[i]]=0;
             
             if(red[b[i]]==0)
                red[b[i]]++;
             
          }
             
          else if(h[a[i]]>1&&red[b[i]]==0)
                  red[b[i]]++;
      }
      h[a[i]]--;
      h[b[i]]++;
      
    }
    
   // for(i=0;i<100009;i++)
    //  cout<<red[i]<<" ";
     // cout<<endl;
      
    for(i=0;i<100009;i++)
    {
        if(red[i]==1)
          c++;
    }
   cout<<c;
 }