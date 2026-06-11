#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long int> sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    int ans = 1;
    for(int i = n-2; i >= 0; i--){
        if(sum[i] >= (a[i+1]+1)/2){
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}