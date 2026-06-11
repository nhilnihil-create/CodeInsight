#include <iostream>

using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    int rankAll=0;
    int rankB=0;
    for (int i=0; i<N; i++){
        if (S.at(i)=='a') {
            if(rankAll < (A+B)) {
                rankAll++;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (S.at(i)=='b') {
            if(rankAll < (A+B) && rankB < B){
                rankAll++;
                rankB++;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}