#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n;
    cin>>n;
   long long int a[n],i,j=1,k=0,l,p=0,v;
   long long int h[n],f[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    for(i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            j++;
        }
        else{
          h[k++]=a[i];
          f[p++]=j;
          j=1;
    }
    }
    h[k]=a[n-1];
    f[p]=j;
  /*  for(i=0;i<=p;i++){
        cout<<f[i]<<endl;
    }*/
    for(i=0;i<=p;i++){
        if(f[i]>=4){
            cout<<(h[i]*h[i])<<endl;
            return 0;
        }
        else if(f[i]>=2){
               // cout<<"i="<<i<<endl;
            for(v=i+1;v<=p;v++){
                if(f[v]>=2){
                   // cout<<"i="<<i<<endl;
                    cout<<(h[i]*h[v])<<endl;
                    return 0;
                }
            }
            break;
        }
    }
    cout<<0<<endl;
}