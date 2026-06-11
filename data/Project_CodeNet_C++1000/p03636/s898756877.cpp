// i18n
#include <iostream>
using namespace std;

int main() {
    int counter;
    string S;

    cin >> S;
    counter = S.size() - 2;
    cout << S[0] + to_string(counter) + S[S.size()-1] << endl;
}