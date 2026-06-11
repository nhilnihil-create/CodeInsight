#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    queue<char> Acard;
    queue<char> Bcard;
    queue<char> Ccard;

    rep(i, A.size()) Acard.push(A[i]);
    rep(i, B.size()) Bcard.push(B[i]);
    rep(i, C.size()) Ccard.push(C[i]);

    char turn = Acard.front();
    Acard.pop();

    char winner;
    bool end = false;
    while(end == false) {
        if(turn == 'a') {
            if(Acard.empty()) {
            winner = 'A';
            end = true;
            break;
            }
            turn = Acard.front();
            Acard.pop();
        }
        else if(turn == 'b') {
            if(Bcard.empty()) {
            winner = 'B';
            end = true;
            break;
            }
            turn = Bcard.front();
            Bcard.pop();
        }
        else if(turn == 'c') {
            if(Ccard.empty()) {
            winner = 'C';
            end = true;
            break;
            }
            turn = Ccard.front();
            Ccard.pop();
        }
    }

    cout << winner << endl;
}