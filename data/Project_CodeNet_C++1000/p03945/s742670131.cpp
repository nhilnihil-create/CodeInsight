#include<iostream>
#include<string>

using namespace std;

string str;

int main() {
    cin >> str;
    int N = str.size();

    int ans = 0;
    char curr, prev = str.back();
    for (int i = N - 2; 0 <= i; i--) {
        curr = str[i];
        if (curr == prev)
            continue;
        prev = curr;
        ans++;
    }
    cout << ans << endl;
    return 0;
}