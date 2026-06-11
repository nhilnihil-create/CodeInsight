#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000;
int A[maxn];
int main(){
    ios::sync_with_stdio(false);
    int N, ans = 0;
    cin >> N;
    map<int, int> mp;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
        mp[A[i]] = i;
    }
    sort(A, A + N);
    for(int i = 0; i < N; i += 2) ans += mp[A[i]] & 1;
    cout << ans;
    return 0;
}