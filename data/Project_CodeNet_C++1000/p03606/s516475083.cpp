#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        sum = sum + (r - l + 1);
    }
    //cout <<  << endl;
    // if (cnt == 3){
    //     cout << "Three" << endl;
    // }
    // if (cnt == 4){
    //     cout << "Four" << endl;
    // }
    cout << sum << endl;

    return 0;

}



