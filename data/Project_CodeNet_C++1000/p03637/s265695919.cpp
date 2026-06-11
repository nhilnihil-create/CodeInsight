#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int even = 0; // 4の倍数ではない偶数
    int odd = 0; //奇数
    int even4 = 0; // 4の倍数
    for (int i = 0; i < N; i++) {
        int a;cin>>a;
        if (a % 4 == 0) even4++;
        else if (a % 2 == 0) even++;
        else odd++;
    }
    if (odd <= even4) cout << "Yes" << endl;
    else if (odd == even4 + 1) {
        if (odd + even4 == N) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else cout << "No" << endl;
    return 0;
}