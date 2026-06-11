#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;

    uint aval = static_cast<uint>('a');
    uint zval = static_cast<uint>('z');
    vector<int> counters(zval-aval+1, 0);

    for (size_t i=0; i<S.size(); ++i) {
        uint val = static_cast<uint>(S[i]) - aval;
        ++counters[val];
    }
    for (size_t i=0; i<counters.size(); ++i) {
        if (counters[i] == 0) {
            cout << static_cast<char>('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}

