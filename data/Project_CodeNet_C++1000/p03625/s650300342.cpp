#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[100005];
ll ans1,ans2;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(a[i]==a[i-1]){
            if(ans1==0){
                ans1=a[i];
                i=i-1;
            }else{
                ans2=a[i];
                cout<<ans1*ans2<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;

}

