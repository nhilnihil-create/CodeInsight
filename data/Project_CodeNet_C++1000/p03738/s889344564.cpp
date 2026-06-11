#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size()) {
        cout << "GREATER" << endl;
    } else if (a.size() < b.size()) {
        cout << "LESS" << endl;
    } else {
        for (int i = 0; i < a.size(); ++i) {
            string sai, sbi;
            sai = a.at(i);
            sbi = b.at(i);
            int ai, bi;
            ai = stoi(sai);
            bi = stoi(sbi);
            if (ai > bi) {
                cout << "GREATER" << endl;
                break;
            } else if (ai < bi) {
                cout << "LESS" << endl;
                break;
            }
            if (i == a.size() - 1) {
                cout << "EQUAL" << endl;

            }
        }
    }
}
