#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    int ans1 = -1;
    int ans2 = -1;
    for (int i=0; i<S.length()-1; i++) {
        if (S[i]==S[i+1]) {
            ans1 = i+1;
            ans2 = i+2;
        }
    }
    for (int i=0; i<S.length()-2; i++) {
        if (S[i]==S[i+2]) {
            ans1 = i+1;
            ans2 = i+3;
        }
    }
    cout << ans1 << " " << ans2 << endl;
}