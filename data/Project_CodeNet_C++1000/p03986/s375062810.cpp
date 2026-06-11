#include <bits/stdc++.h>
using namespace std;
int main(){
    int answer = 0, s = 0;
    string S;
    cin >> S;
    for (int i = 0; i < (int) S.size() ;i++) {
        if (S.at(i) == 'S') {
            s++;
        }
        if (S.at(i) == 'T' && s > 0) {
                s--;
                answer++;
        }
    }
    cout << (int)S.size() - 2 * answer << endl;
}