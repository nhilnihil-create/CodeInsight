#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int arr;
int ans;
int fact;
int cur;
int main(){
    scanf("%d" , &n);
    cur = 0;
    fact = 1;
    ans = 1;
    while(n--){
        scanf("%d" , &arr);
        ++cur;
        if(arr < 2 * cur - 1){
            ans = (1LL * ans * cur) % mod;
            --cur;
        }
    }
    while(cur--){
        ans = (1LL * ans * (cur + 1LL)) % mod;
    }
    printf("%d\n" , ans);
}