#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ans=0;
    int N,X,a[100010]={};
    cin>>N>>X;

    for(int i=1;i<=N;i++){
        cin>>a[i];

        if(i!=1){
            if(a[i-1]+a[i]>X){
                ans+=a[i-1]+a[i] - X;
                
                a[i]=max(0,X-a[i-1]);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}