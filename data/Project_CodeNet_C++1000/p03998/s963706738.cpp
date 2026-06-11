// 3人でカードゲームイージー
#include <bits/stdc++.h>
using namespace std;

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    queue<char> qa, qb, qc;
    for (int i; i < sa.size(); i++) {
        qa.push(sa.at(i));
    }
    for (int i; i < sb.size(); i++) {
        qb.push(sb.at(i));
    }
    for (int i; i < sc.size(); i++) {
        qc.push(sc.at(i));
    }

    char turn = 'a';
    char winner;
    while ( true ) {
        if (turn == 'a') {
            if ( qa.empty() ) {
                winner = 'A';
                break;
            }
            turn = qa.front();
            qa.pop();
        }
        else if (turn == 'b') {
            if ( qb.empty() ) {
                winner = 'B';
                break;
            }
            turn = qb.front();
            qb.pop();
        }
        else if (turn == 'c') {
            if ( qc.empty() ) {
                winner = 'C';
                break;
            }
            turn = qc.front();
            qc.pop();
        }
    }
    
    cout << winner << endl;
    
}