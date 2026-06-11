#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int N1 = N / 10;
    int N2 = N % 10;
    if (N1 == 9 || N2 == 9) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}