#include<iostream>
using namespace std;

int main() {
    int arr[26] = {0};
    string w; cin >> w;
    for (int i = 0; i < w.size(); i++) {
        arr[w[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
