#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n;
pair<long long, long long> arr[N];

bool check(long long h){
    long long curl = h * arr[n].first, curr = h * arr[n].second;
    for(int i = n - 1; i >= 1; i--){

        bool found1 = false, found2 = false;
        long long k = min(curl / arr[i].first, curr / arr[i].second);
        if(k == 0){
            return false;
        } else {
            long long newl = k * arr[i].first;
            long long newr = k * arr[i].second;
            if(newl <= curl && newr <= curr){
                curl = newl;
                curr = newr;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    long long g = arr[n].first + arr[n].second;
    long long l = 1, r = 1000000000000000000 / g, ans = -1;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << g * ans << '\n';
    return 0;
}