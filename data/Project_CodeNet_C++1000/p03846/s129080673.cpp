#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100005

int main(){
    int n; cin >> n;
    ll c[MAX];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c, c+n);
    if(n%2 != 0){
        if(c[0] != 0){
            
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 0; i < n/2; i++){
        bool f = true;
        if(n%2 != 0){
            int j = i+1;
            if(c[2*j-1] != c[2*j] || c[2*j-1] %2 != 0 || c[2*j] %2 != 0) f = false;
        }else{
            if(c[2*i+1] != c[2*i] || c[2*i+1] %2 == 0 || c[2*i] %2 == 0) f = false;
        }

        if(!f){
            cout << 0 << endl;
            return 0;
        }
        ans = ans*2%mod;
    }
    cout << ans << endl;
    return 0;
}