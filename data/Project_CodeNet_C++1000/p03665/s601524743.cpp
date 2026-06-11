#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n,p;
    cin >> n >> p;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp%2 == 0) cnt++;
    } 
    if(cnt == n && p == 1) cout << 0 << endl;
    else if(cnt == n && p == 0) cout << (1ll << n) << endl;
    else cout << (1ll << n-1) << endl;
}