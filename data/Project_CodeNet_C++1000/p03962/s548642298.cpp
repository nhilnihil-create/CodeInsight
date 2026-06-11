#include <iostream>
using namespace std;

int main(void) {
    int a,b,c;cin>>a>>b>>c;
    int result = 1;
    if (a != b) {
        result++;
        if (a != c && b != c) result++;
    } else {
        if (a != c) result++;
    }
    cout << result << endl;

    return 0;
}