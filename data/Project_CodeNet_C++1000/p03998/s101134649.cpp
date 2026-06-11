#include "bits/stdc++.h"

using namespace std;

void Main() {
    string SA, SB, SC;
    cin >> SA >> SB >> SC;

    int ia = 0;
    int ib = 0;
    int ic = 0;
    char turn = 'a';
    while (true) {
        if (turn == 'a') {
            if (ia == SA.size()) {
                cout << "A" << endl;
                return;
            }
            else {
                turn = SA[ia];
                ++ia;
            }
        }
        else if (turn == 'b') {
            if (ib == SB.size()) {
                cout << "B" << endl;
                return;
            }
            else {
                turn = SB[ib];
                ++ib;
            }
        }
        else {
            if (ic == SC.size()) {
                cout << "C" << endl;
                return;
            }
            else {
                turn = SC[ic];
                ++ic;
            }
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
