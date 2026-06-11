#include<iostream>
#include<string>

using namespace std;

int main (void) {
    string s;
    long long k;
    cin >> s >> k;
    for (auto& e : s) {
        if (e == 'a') continue;
        if (k > 'z' - e) {
            k -= ('z' - e + 1);
            e = 'a';
        }
    }
    auto lastIt = (s.end()-1);
    *lastIt = ((long long)*lastIt + k - 'a') % ('z' - 'a' + 1) + 'a';
    cout << s << endl;
}
