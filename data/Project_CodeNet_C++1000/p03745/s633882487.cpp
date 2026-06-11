#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int before = 1e9 + 7;
    int swit = 0;
    int result = 1;
    for (int i = 0; i < N; i++) {
        int A;cin>>A;
        if (before < 1e9 + 7) {
            if (swit > 0 && before > A) {
                result++;
                swit = 0;
            } else if (swit < 0 && before < A) {
                result++;
                swit = 0;
            } else {
                if (before < A) swit = 1;
                else if (before > A) swit = -1;
            }
        }
        before = A;
    }
    cout << result << endl;
    return 0;
}