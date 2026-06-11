#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;
 
//const int MOD=998244353;
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n,sum=0;
    cin>>n;
    
    vector<long long> v(n), l(n);
    
    for(long long &i:v)cin>>i,sum+=i;
    
    long long g=n*(n+1)/2;
    
    if(sum%g){
        cout<<"NO";
        return 0;
    }
    long long op=sum/g;
    
    long long lds=0;
    for(int i=0; i<n; i++){
        l[i]=v[i]-v[i?i-1:n-1];
    }
    
    long long o2=0;
    for(int i=0; i<n; i++){
        if(op-l[i]<0 || (op-l[i])%n){
            cout<<"NO";
            return 0;
        }
        o2+=(op-l[i])/n;
        
    }
    cout<<(o2==op?"YES":"NO");
    return 0;
    
    
}
