#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <functional>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0;i < n;i++)cin >> a[i];

    sort(a.begin(),a.end());
    
    if(n == 1){
        cout << 1 << endl;
    }
    else if(n % 2 == 0){
        int now = 1;
        for(int i = 0;i < n;i++){
            if(a[i] == a[i+1] && a[i] == now){
                now += 2;
                i++;
            }
            else{
                cout << 0 << endl;
                return 0;
            }
        }
        
        ll ans = 1;
        for(int i = 0;i < n/2;i++){
            ans *= 2;
            ans %= MOD;
        }

        cout << ans << endl;
    }
    else{
        if(a[0] != 0){
            cout << 0 << endl;
            return 0;
        }
        
        int now = 2;
        for(int i = 1;i < n;i++){
            if(a[i] == a[i+1] && a[i] == now){
                i++;
                now += 2;
            }
            else{
                cout << 0 << endl;
                return 0;
            }
        }

        ll ans = 1;
        for(int i = 0;i < n/2;i++){
            ans *= 2;
            ans %= MOD;
        }

        cout << ans << endl;
    }
}

