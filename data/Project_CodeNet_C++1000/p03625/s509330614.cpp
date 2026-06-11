#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int i,idx,k,j,n,a[100000],mx=0;
    map<long long int,long long int>m;
    vector<long long int>v;
    cin>>n;
    idx=0;
    for(i=0;i<n;i++){cin>>a[i];}
    sort(a,a+n,greater<int>());
    for(i=0;i<n;i++){m[a[i]]++;}
     for(j=0;j<n;j++){
   if(m[a[j]]>=4){
            if(idx==0){v.push_back(a[j]);
       v.push_back(a[j]);idx=1;m[a[j]]=-1;}
        else{v.push_back(a[j]);m[a[j]]=-1;}
        }
   else if(m[a[j]]>=2&&m[a[j]]<=3){
      v.push_back(a[j]);m[a[j]]=-1;idx=1;
    }
      }
    if(v.size()<2){cout<<"0\n";}
    else{cout<<v[0]*v[1]<<endl;}
     }