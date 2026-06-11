#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(3*n);
    for(int i=0; i<3*n; i++) 
        cin >>a[i];
    ll ans = 0;

    sort(a.begin(), a.end());

    for(int i=n; i<3*n; i++){
        int tmp = i - n;
        if(tmp%2==0){
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}