#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[100005];
ll k;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==1){
            k++;
        }
    }
    if(k%2==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}
