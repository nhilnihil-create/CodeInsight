#include<bits/stdc++.h>
using namespace std;
map<int,int> m;

void call(int x){

    while(x%2==0){
        m[2]++;
        x/=2;
    }
    for(int i=3; i<=sqrt(x); i+=2){
        while(x%i==0){
            m[i]++;
            x/=i;
        }
    }
    if(x>1)
        m[x]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin>>n;

    for(int i=2; i<=n; i++){
        call(i);
    }
    long long ans=1,mod=1e9+7;

    for(auto it: m){
        ans*=(it.second+1);
        ans%=mod;
    }

    cout<<ans<<endl;
    return 0;
}
