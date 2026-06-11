#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum4=0;
    ll sum2=0;
    ll sumodd=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(0==a[i]%4){
            sum4++;
        }else if(0==a[i]%2){
            sum2++;
        }else{
            sumodd++;
        }
    }
    
    string ans;
    if(0==sum2){
        if(sum4+1>=sumodd){
            ans="Yes";
        }else{
            ans="No";
        }
    }else{
        if(sum4>=sumodd){
            ans="Yes";
        }else{
            ans="No";
        }
    }
    cout<<ans<<endl;
    return 0;
}