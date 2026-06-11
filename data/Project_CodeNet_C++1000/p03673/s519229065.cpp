#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> v;
    
    for(int i=0;i<n;i++)
    {
        
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> ans(n);

     if(n%2==0)
     {
          int mid=n/2;


          for(int i=0;i<n;i+=2)
          {
              int in=i/2;
              ans[mid+in]=v[i];
              ans[mid-in-1]=v[i+1];
          }   


          for(auto i:ans)
          cout<<i<<" ";
          cout<<endl;
     }
     else
     {

                ans[n/2]=v[0];
         for(int i=1;i<n;i+=2)
         {
            ans[n/2+(i+1)/2]=v[i];
            ans[n/2-(i+1)/2]=v[i+1];
            
         }
         for(auto i:ans)
         cout<<i<<" ";
         cout<<endl;

     }
}