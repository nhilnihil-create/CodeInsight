#include <bits/stdc++.h> 
using namespace std; 

int main()
{
    long long int n,t;
    cin>>n;
    t=n*2;
    vector<long long int> v;
    while(t--)
    {
        long long int k;
        cin>>k;
        v.push_back(k);
      
    }
    sort(v.rbegin(),v.rend());
    
    long long int sum=0;
    for(long long int i=1;i<(2*n);i+=2)
    {
      
        sum+=v[i];
    }
    cout<<sum;
    
}