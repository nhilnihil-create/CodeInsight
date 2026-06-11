#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    ll mini=0, ans;
    for(int i=0; i<n; i++){
        ll a, b;   cin >> a >> b;
        if(mini<a){
            ans = a+b;
            mini = a;
        }
    }
    cout << ans << endl;
    


}