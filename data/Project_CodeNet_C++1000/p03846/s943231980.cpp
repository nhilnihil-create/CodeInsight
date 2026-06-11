#include "bits/stdc++.h"

using namespace std;

int main() {
	long long n, ans = 1;
	cin >> n;
	long long arr[n];
	for(long long i = 0; i < n; ++i){
        cin >> arr[i];
	}
	sort(arr, arr + n);
	if(n == 1){
        cout << 1;
	}else if(n % 2 == 0){
        if(arr[0] == 0){
            cout << 0;
            return 0;
        }else{
            for(long long i = 0; i < n; i += 2){
                if(arr[i] != arr[i + 1]){
                    cout << 0;
                    return 0;
                }
            }
            for(long long i = 0; i < n / 2; ++i){
                ans <<= 1;
                ans %= 1000000007;
            }
        }
        cout << ans;
	}else{
        if(arr[0] != 0 || arr[1] == 0){
            cout << 0;
            return 0;
        }else{
            for(long long i = 1; i < n; i += 2){
                if(arr[i] != arr[i + 1]){
                    cout << 0;
                    return 0;
                }
            }
            for(long long i = 0; i < n / 2; ++i){
                ans <<= 1;
                ans %= 1000000007;
            }
            cout << ans;
        }
	}

	return 0;

}
