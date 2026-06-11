#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> clr(3, 0);
    cin >> clr[0] >> clr[1] >> clr[2];
    sort(clr.begin(), clr.end());
    int ans = 1, tmp = clr[0];
    for(int x : clr){
        if(x != tmp) ans++;
        tmp = x;
    }
    cout << ans << endl;
}