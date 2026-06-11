#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    long long x;
    cin >> N >> x;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    long long res = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            if(a[i] >= x){
                ans += a[i] - x;
                res = x;
            }
            else res = a[i];
        }
        else if(a[i] >= x - res){
            ans += a[i] - (x - res);
            res = x - res;
        }
        else res = a[i];
    }
    cout << ans << endl;
}