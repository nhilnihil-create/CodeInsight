#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    int l[2*n];
    for(int i = 0; i < 2*n; i++){
        cin >> l[i];
    }
    sort(l,l+2*n);
    int ans = 0;
    for(int i = 0; i < 2*n-1; i+=2){
        ans += min(l[i], l[i+1]);
    }
    cout << ans << endl;
    return 0;
}