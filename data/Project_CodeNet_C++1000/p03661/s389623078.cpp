#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int i,m,j,l,n,a=0,b,x=10000000000;
    vector<long long int>ar;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        ar.push_back(j);
    }
  long long  int sum=0;
    for(l=0;l<n;l++){
        sum+=ar[l];
    }
    for(m=0;m<n-1;m++){
       a+=ar[m];b=sum-a;
        x=min(x,abs(a-b));
    }
       
    cout<<x<<endl;
    }