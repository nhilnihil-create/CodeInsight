/*
 #pragma GCC target ("avx2")
 #pragma GCC optimize ("Ofast")
 #pragma GCC optimize ("unroll-loops")
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
const long long N=2e5;
long long a[N];
long long ans=-1,n;
long long A,B;
bool good(long long x){
    long long b[n];
    for(long long i=1;i<=n;i++){
        b[i] = max(0ll,a[i]-(B * x) );
    }
    for(long long i=1;i<=n;i++){
        if(b[i]>0){
            long long cur=(b[i]+(A-B)-1)/(A-B);
            if(x<cur)return 0;
            x-=cur;
            
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>A>>B;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long l=0,r=1e9;
    while(l<=r){
        long long m=(l+r)/2;
        if(good(m)){
            r=m-1;
            ans=m;
        }else{
            l=m+1;
        }
    }
    cout<<ans;
    return 0;
}
