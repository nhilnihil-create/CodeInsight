#include<iostream>
using namespace std;

int main() {
    string S; cin >> S;
    int arr[26] = {0};
    string ans = "yes";
    for (int i = 0; i < S.size(); i++) {
        if (arr[S[i] - 'a'] == 0) {
            arr[S[i] - 'a'] = 1;
        } else {
            ans = "no";
        }
    }
    cout << ans << endl;
}
