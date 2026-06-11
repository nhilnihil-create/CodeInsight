#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <cstdio>

using namespace std;

int n;
string a,b;
long long mod = 1e9 + 7;

int main(){
    cin >> n;
    cin >> a >> b;

    long long ans = 1;
    long long cur = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            if(cur == -1){
                ans *= 3;
                ans %= mod;
            }
            else if(cur == 0){
                ans *= 2;
                ans %= mod;
            }
            cur = 0;
        }
        else{
            if(cur == -1){
                ans *= 6;
                ans %= mod;
            }
            else if(cur == 0){
                ans *= 2;
                ans %= mod;
            }
            else{
                ans *= 3;
                ans %= mod;
            }
            cur = 1;
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
