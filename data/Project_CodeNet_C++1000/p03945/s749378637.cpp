#include<iostream>
#include<string>

using namespace std;

string str;

int main() {
    cin >> str;
    int N = str.size();

    int ans = 0;
    for (int i = 1; i < N; i++) {
        if(str[i]!=str[i-1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}