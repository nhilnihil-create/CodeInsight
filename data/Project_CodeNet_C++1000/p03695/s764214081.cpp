#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0,d;
    cin>>n;
    vector<long long> a(9,0);
    f(i,0,n){
        cin>>d;
        if(d>=3200){
            a[8]++;
        }
        else{
            a[d/400]++;
        }
    }
    f(i,0,8){
        if(a[i]>0){
            ans++;
        }
    }
    if(ans==0){
        cout<<1<<" "<<a[8]<<endl;
    }
    else{
        cout<<ans<<" "<<ans+a[8]<<endl;
    }
    return 0;
}
