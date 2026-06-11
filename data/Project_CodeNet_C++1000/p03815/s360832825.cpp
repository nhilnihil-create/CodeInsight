#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll int ara[]={11,10,9,8,7};
    ll int n,i,j,k,mini=180000000000000000;
    cin>>n;

    if(n<=6) cout<<1<<endl;
    else{
        //for(i=0;i<5;i++){
            ll int mod=n%11;
            ll int sum=n/11;
            sum=(sum*2);
            if(mod>0 && mod<=6) sum++;
            else if(mod>6 && mod<11) sum+=2;
            //mini=min(sum,mini);
        //}
        cout<<sum<<endl;
    }
}
