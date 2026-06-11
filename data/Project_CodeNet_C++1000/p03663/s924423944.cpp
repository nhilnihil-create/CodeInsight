#include <iostream>

using namespace std;

int main(void) {
    int64_t no  =   999'999'999'999;
    int64_t yes = 9'999'999'999'999;
    while(no + 1L < yes) {
        int64_t mid = (no + yes) / 2;
        cout << "? " << mid << endl;
        char res;
        cin >> res;
        if(res == 'Y') {
            yes = mid;
        } else {
            no = mid;
        }
    }

    while(yes % 10L == 0) {
        yes /= 10L;
    }

    if(to_string(yes).size() != to_string(yes+1).size()) {
        cout << "! " << yes << endl;
        return 0;
    }

    while(true) {
        cout << "? " << yes+1L << endl;
        char res;
        cin >> res;
        if(res == 'Y') {
            cout << "! " << yes << endl;
            break;
        } else if(yes > 100'000'000) {
            cout << "! " << yes << endl;
        } else {
            yes *= 10L;
        }
    }
    return 0;
}
