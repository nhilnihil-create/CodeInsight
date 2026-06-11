
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int A, B; cin >> A >> B;
    cout << ((A+B >= 10) ? "error" : to_string(A+B)) << endl;
    return 0;
}
