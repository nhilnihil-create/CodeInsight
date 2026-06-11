#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(void){
    ll n;
    cin >> n;
    string str, t;
    cin>>str>>t;
    ll result = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){ 
            if(str[i+j]!=t[j]){ 
                result=max(result, j);
                break;
            }
            if(j == n-1)
                result = n;
        }
    }
    cout<<n*2-result;
    return 0;
}
