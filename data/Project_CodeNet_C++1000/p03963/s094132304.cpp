#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a,b,ans=1;
    cin>>a>>b;
    ans*=b;
    f(i,1,a){
        ans*=b-1;
    }
    cout<<ans<<endl;
    return 0;
}
