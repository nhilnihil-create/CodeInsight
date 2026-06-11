#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long ans=1,n;
    cin>>n;
    f(i,1,n+1){
        ans*=i;
        ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
