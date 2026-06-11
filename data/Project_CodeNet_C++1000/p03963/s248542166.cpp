#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    ull n, k;
    cin >> n >> k;
    ull ans = k * pow(k-1, n-1);
    cout << ans;
}
