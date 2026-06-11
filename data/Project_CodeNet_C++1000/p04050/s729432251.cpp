#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) cin >> A[i];

    // 1 個の場合
    if (A.size() == 1) {
        cout << A[0] << endl;
        if (A[0] > 1) {
            cout << 2 << endl;
            cout << A[0]-1 << " " << 1 << endl;
        }
        else {
            cout << 1 << endl;
            cout << 1 << endl;
        }
        return 0;
    }

    // 偶数 / 奇数
    vector<int> odd, even;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] % 2 == 1) odd.push_back(A[i]);
        else even.push_back(A[i]);
    }
    if (odd.size() > 2) {
        cout << "Impossible" << endl;
        return 0;
    }

    // 求める
    vector<int> resA;
    if (odd.size() >= 1) resA.push_back(odd[0]);
    for (int i = 0; i < even.size(); ++i) resA.push_back(even[i]);
    if (odd.size() == 2) resA.push_back(odd.back());

    vector<int> resB;
    resB.push_back(resA[0] + 1);
    for (int i = 1; i+1 < resA.size(); ++i) resB.push_back(resA[i]);
    if (resA.back() > 1) resB.push_back(resA.back() - 1);

    // 出力
    for (int i = 0; i < resA.size(); ++i) {
        if (i) cout << " ";
        cout << resA[i];
    }
    cout << endl;
    cout << resB.size() << endl;
    for (int i = 0; i < resB.size(); ++i) {
        if (i) cout << " ";
        cout << resB[i];
    }
    cout << endl;
}
