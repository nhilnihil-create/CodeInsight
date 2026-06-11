#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,c,k;
    cin >> n >> c >> k;
    int t[n];
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t,t+n);
    //tmpにはそのバスの最小時間、numにはバスの人数、ansはバスの数を表す。
    int tmp = t[0];
    int num = 1;
    int ans = 0;
    for(int i = 1;i < n; i++){
        //人数に余裕がある場合は条件を満たすか確認
        if(num < c){
            //最小値+k以下であれば乗せられる
            if(t[i] <= tmp+k){
                num++;
            }else{
                ans++;
                num = 1;
                tmp = t[i];
            }
        }else if (num == c){
            ans++;
            num = 1;
            tmp = t[i];
        }
    } 
    ans++;
    cout << ans << endl;

    return 0;
}


