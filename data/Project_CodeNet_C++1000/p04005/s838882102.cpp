#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a,b,c,ans;
    cin>>a>>b>>c;
    if(a%2==0||b%2==0||c%2==0){
        cout<<0<<endl;
    }
    else{
        ans=a*b;
        ans=min(ans,b*c);
        ans=min(ans,c*a);
        cout<<ans<<endl;
    }
    return 0;
}
