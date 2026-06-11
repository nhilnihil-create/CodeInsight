#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int h = N / 100;
    N = N % 100;
    int j = N / 10;
    N = N % 10;
    int i = N;
    if (h == i) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}