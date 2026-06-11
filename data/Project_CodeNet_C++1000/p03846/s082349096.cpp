#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int>vec;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    if(vec.size()%2!=0){
        for(int i = 1;i < n;i+=2){
            if(vec[i] != vec[i+1]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(vec.size() == 1){
            cout << 1 << endl;
            return 0;
        }
        ll ans = 2;
        for(int i = 1;i < (vec.size()-1)/2;i++){
            ans *=2;
            ans %=1000000007;
        }
        cout << ans << endl;
        //ll ans = pow(2,(vec.size()-1)/2);
        //cout << ans%1000000007  << endl;
    }else{
        for(int i = 0;i < n;i+=2){
            if(vec[i] != vec[i+1]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(vec.size() == 1){
            cout << 1 << endl;
            return 0;
        }
        ll ans = 2;
        for(int i = 1;i < vec.size()/2;i++){
            ans *=2;
            ans %=1000000007;
        }
        cout << ans << endl;
        //ll ans = pow(2,vec.size()/2);
        //cout << ans%1000000007  << endl;
    }
}



