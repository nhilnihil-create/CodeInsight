#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[n],ans=0;
    f(i,0,n){
        cin>>a[i];
        ans+=a[i];
    }
    sort(a,a+n);
    if(ans%10!=0){
        cout<<ans<<endl;
        return 0;
    }
    else{
        f(i,0,n){
            if(a[i]%10!=0){
                cout<<ans-a[i]<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
    return 0;
}
