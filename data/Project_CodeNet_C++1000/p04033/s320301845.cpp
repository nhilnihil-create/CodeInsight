#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >>a >>b;
    string ret;
    if(a>0) {ret = "Positive";}  // 0 < a <= b
    if(a==0) {ret = "Zero";}      // 0 = a <= b
    if(a<0) {
        if (b>=0) {ret = "Zero";} // a < 0 <= b
        if (b<0) {ret = ((b-a)%2==0) ? "Negative" : "Positive";}
    }
    cout << ret << endl;
    return 0;
}