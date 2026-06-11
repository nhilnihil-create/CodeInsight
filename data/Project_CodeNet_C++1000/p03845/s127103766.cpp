
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n; //問題数
    cin >> n;

    vector<int> time(n); //各問題を解くのにかかる時間
    for (int i = 0; i < n; i++) {
        cin >> time.at(i);
    }
    // 元々の合計時間
    int sum;
    sum = accumulate(time.begin(),time.end(),0);

    int m; cin >>m; //ドリンクの数

    for(int i = 0; i < m; i++){
        int ans, p, x;
        cin >> p >> x;
        ans = sum + x - time.at(p - 1);
        cout << ans << endl;
    }
    
}