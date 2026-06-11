#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long A, B, C;
    cin >> A >> B >> C;
    vector<long long> vals{A, B, C};
    sort(vals.begin(), vals.end());

    long long max_val = vals[2];
    long long ans = 0;
    if(max_val%2 == 1){
        ans = vals[0]*vals[1];
    }

    cout << ans << endl;
    return 0;

}