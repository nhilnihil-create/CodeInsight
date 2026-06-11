#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<long long> a(7);
    for(int i = 0; i < 7; i++){
        cin >> a[i];
    }
    long long ans = 0;
    ans += a[0] & -2LL;
    ans += a[1];
    ans += a[3] & -2LL;
    ans += a[4] & -2LL;
    long long ans2 = 0;
    if(a[0] > 0 && a[3] > 0 && a[4] > 0){
        ans2 += 3;
        a[0]--; a[3]--; a[4]--;
    }
    ans2 += a[0] & -2LL;
    ans2 += a[1];
    ans2 += a[3] & -2LL;
    ans2 += a[4] & -2LL;
    cout << max(ans, ans2) << endl;
    return 0;
}
