#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;

const int mod = 1e9+7;

int n;
string a[2];

int main(){
    cin >> n >> a[0] >> a[1];
    long long ways = 1;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(a[0][0] == a[1][0]){
                ways *= 3;
            } else {
                ways *= 6;
                i ++;
            }
            continue;
        }
        if(a[0][i] == a[1][i]){
            if(a[0][i - 1] != a[1][i - 1])
                ways *= 1;
            else
                ways *= 2;
            ways %= mod;
            continue;
        }
        if(a[0][i - 1] == a[1][i - 1]){
            ways *= 2;
            ways %= mod;
            i++;
            continue;
        }
        ways *= 3;
        ways %= mod;
        i++;
    }
    printf("%lld\n" , ways);
}
