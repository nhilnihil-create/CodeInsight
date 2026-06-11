#include<iostream>
#include<vector>
using namespace std;

int main(){

    long long n = 50;
    long long k; cin >> k;
    long long a = k / n;
    long long b = k % n;
    vector<long long> ans(n, a + n - 1);
    for(long long i = 0; i < b; i++){
        //i番目を50増やす
        //その他を-1する
        for(long long j = 0; j < n; j++){
            if(i == j){
                ans[j] += n;
            }else{
                ans[j]--;
            }
        }
    }

    cout << n << endl;
    for(int i = 0; i < n-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;
    return 0;
}