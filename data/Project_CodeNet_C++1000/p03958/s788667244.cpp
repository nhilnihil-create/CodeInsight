#include<bits/stdc++.h>
using namespace std;
int n,T,k,a;
int main() 
{
    cin>>n>>T;
    for(int i=1;i<=T;i++) 
        cin>>a,k=max(k,a);
    cout<<max(k-1-(n-k),0)<<endl;
    return 0; 
}