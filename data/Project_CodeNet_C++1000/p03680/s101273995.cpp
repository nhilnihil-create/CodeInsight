#include <iostream>
using namespace std;

int main() {
    int N, tmp, A[100000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A[i] = tmp - 1; //配列のインデックスに調整
    }
    int index = 0, res = -1;
    for (int i = 0; i < N; i++) {
        index = A[index];
        if (index == 1) {
            res = i + 1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}