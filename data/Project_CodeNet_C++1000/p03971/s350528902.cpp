#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int N,A,B;
    string S;

    cin >> N >> A >> B;
    cin >> S;

    int acnt = 0;
    int bcnt = 0;
    int tsuuka = A + B;

    for (int i=0; i<N; i++){
        if (S.at(i) == 'c'){
            cout << "No" << endl;
        }

        if (S.at(i) == 'a'){
            if (acnt + bcnt < tsuuka){
                cout << "Yes" << endl;
                acnt++;
            }
            else
            {
                cout << "No" << endl;
            }
            
        }

        if (S.at(i) == 'b'){
            if (acnt + bcnt < tsuuka && bcnt < B){
                cout << "Yes" << endl;
                bcnt++;
            }
            else{
                cout << "No" << endl;
            }
        }

    }

}
