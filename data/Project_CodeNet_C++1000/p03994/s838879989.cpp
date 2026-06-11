#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


int main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    for (int i=0; i<n; i++) {
        if (s[i]!='a' && (26-(s[i]-'a')) <= k) {
            k -= (26-(int)(s[i]-'a'));
            s[i] = 'a';
        }
    }
    s.back() = 'a' + ((int)(s.back() - 'a') + k)%26;

    cout << s << endl;
}