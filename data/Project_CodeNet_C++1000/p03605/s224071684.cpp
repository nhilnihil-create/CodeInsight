#include <iostream>
using namespace std;

int main (void) {
    std::string n;

    cin >> n;

    if (n[0] == '9' || n[1] == '9'){
        
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
