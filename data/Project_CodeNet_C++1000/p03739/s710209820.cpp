#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#define imie(...) __debug_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define imie(...)
#define endl '\n'
#pragma GCC optimize("O2")
#endif

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    int64_t sum = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; ++i){
        int64_t tsum = sum + arr[i];
        if((i&1) && tsum >= 0) {
            cnt1 += abs(arr[i] + 1 + sum);
            //cerr << "CHANGE " << arr[i] << " TO " << -1-sum << endl;
            sum = -1;
        }
        else if(!(i&1) && tsum <= 0){
            // arr[i]* = 1 - sum;
            cnt1 += abs(arr[i] - 1 + sum);
            //cerr << "CHANGE " << arr[i] << " TO " << 1-sum << endl;
            sum = 1;
        }
        else sum = tsum;
    }
    sum = 0;
    for(int i = 0; i < n; ++i){
        int64_t tsum = sum + arr[i];
        if((i&1) && tsum <= 0){
            cnt2 += abs(arr[i] - 1 + sum);
            //cerr << "CHANGE " << arr[i] << " TO " << 1-sum << endl;
            sum = 1;
        }
        else if(!(i&1) && tsum >= 0){
            cnt2 += abs(arr[i] + 1  + sum);
            //cerr << "CHANGE " << arr[i] << " TO " << -1-sum << endl;
            sum = -1;
        }
        else sum = tsum;
    }
    cout << min(cnt1, cnt2) << endl;
}