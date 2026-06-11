#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) {
        cin >> A[i];
    }

    int64_t min_value = 1;
    int64_t ans = 0;
    for (int64_t i = 0; i < N; i++) {
        //min_value未満の価格提示は前のものに吸われるのでダメ
        //A[i]から1以上残るように引く。逆に最後に残るのはできるだけ小さいほうが良い
        //基本的にmin_valueの提示を繰り返していき、最後の1回だけ1になるようなちょっと大きめの提示をする
        //何回できるか
        int64_t time = (A[i] - 1) / min_value;
        ans += time;
        min_value = max(min_value, (time == 0 ? A[i] + 1 : 2));
    }

    cout << ans << endl;
}