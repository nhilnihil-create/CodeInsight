#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld=long double;
 
int main(){
    int t;
    cin>>t;
    int n=2*t;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    
    int p=0,sum=0;
    for(int i=0;i<n;i++){
        if(i%2==0)
        sum+=a[i];
        
    }
    cout<<sum;
    
    return 0;
}