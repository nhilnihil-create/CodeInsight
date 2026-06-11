#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i <= 7; i++) {
        int num = pow(2, i);
        if (num <= N) {
            ans = num;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
