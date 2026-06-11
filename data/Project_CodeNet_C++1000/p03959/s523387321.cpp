#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
const long long MOD = (long long)1e9 + 7;

int main(){
	int n;
    long long ans = 1;
	cin >> n;
    vector<long long> t(n + 2), a(n + 2);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        if(t[i - 1] < t[i] && a[i] > a[i + 1]){
            if(t[i] != a[i]){
                ans = 0;
                break;
            }
        }else if(t[i - 1] == t[i] && a[i] == a[i + 1]){
            ans = (ans * min(t[i], a[i])) % MOD;
        }else if(t[i - 1] < t[i] && a[i] == a[i + 1]){
            if(t[i] > a[i]){
                ans = 0;
                break;
            }
        }else{
            if(t[i] < a[i]){
                ans = 0;
                break;
            }
        }
    }
	cout << ans << endl;
	return 0;
}
