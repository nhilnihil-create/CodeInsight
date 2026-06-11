#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    long long a[3*n];
    f(i,0,3*n){
        cin>>a[i];
    }
    sort(a,a+3*n);
    for(int i=n;i<3*n;i+=2){
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
