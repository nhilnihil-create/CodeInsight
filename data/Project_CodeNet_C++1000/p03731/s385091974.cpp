/*
次の人がやってくるまでの時間がポイントになる
次の人がやってくるまでにT秒以上必要ならば, お湯はT秒出る
次の人がT秒以内にやってくるならば, それまでの時間,お湯が出る
最後の人がボタンを押したあと, お湯がT秒間出ることに注意せよ
*/

#include <bits/stdc++.h>
using namespace std;

long long N, T;
int main(){
    cin >> N >> T;
    
    vector<long long> t(N);
    for (int i = 0; i < N; i++) cin >> t[i];
    
    long long time = 0;
    
    for (int i = 1; i < N; i++){
        time += min(T, t[i]-t[i-1]);
    }
    time += T;
    cout << time << endl;
}