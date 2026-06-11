#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main (){
    int n;cin>>n;
    ll A[n+1],B[n+1];
    for(int i=1;i<=n;i++)cin>>A[i]>>B[i];
    ll res=0,cnt=0;
    for(int i=n;i>=1;i--){
        A[i]+=cnt;
        ll closest_mul = A[i]/B[i] + ((A[i]%B[i])>0);
        closest_mul*=B[i];
        //cout<<"closest multiple of "<<B[i]<<" is "<<closest_mul<<" where A["<<i<<"] is  = "<<A[i]<<endl;
        ll need = closest_mul - A[i];
        res+=need;
        cnt+=need;
    }
    cout<<res<<endl;
    return 0;
}
