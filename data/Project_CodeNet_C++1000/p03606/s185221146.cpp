#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int result = 0;
    for (int i = 1;i <= N; i++) {
        int l,r;cin>>l>>r;
        result += r - l + 1;
    }
    cout << result << endl;
    return 0;
}