#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll A[200000];
ll sm(ll* A,ll n){
    ll s= 0;
    for (int i = 0; i < n; ++i) {
        s += A[i];
    }
    return s;
}

ll digit_sum(ll x){
    ll sum = 0;
    while(x){
       sum += x%10;
       x /= 10;
    }
    return sum;
}
unordered_set <ll> hashset;
int main() {
    int n;
    cin >> n;
    bool cond =1;
    int cnt = 0;
    int sum =0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >>t;
        if(t == i+1){
            cnt ++;
        }
        else {
            sum += (cnt+1)/2;cnt =0;
        }
    }
    sum += (cnt+1)/2;
    cout << sum;
}