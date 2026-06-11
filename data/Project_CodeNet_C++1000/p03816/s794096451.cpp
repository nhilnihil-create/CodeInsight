#include "bits/stdc++.h"

using namespace std;

long long arr[100001];

int main() {
    long long n;
    cin >> n;
    for(long long i = 0; i < n; ++i){
        long long tmp; cin >> tmp;
        arr[tmp]++;
    }
    for(long long i = 0; i < 100001; ++i){
        if(arr[i] > 2){
            if(arr[i] % 2 != 0){
                arr[i] = 1;
            }else arr[i] = 2;
        }
    }
    long long ans = 0, cnt = 0;
    for(long long i = 0; i < 100001; ++i){
        if(arr[i] == 2){
            cnt++;
        }
        if(arr[i] >= 1)ans++;
    }
    if(cnt % 2 == 0)cout << ans;
    else cout << ans - 1;
	return 0;

}
