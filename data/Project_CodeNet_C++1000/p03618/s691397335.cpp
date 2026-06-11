#include <iostream>
#include <map>

using namespace std;

long long len, total = 0;
string s;
map<long long, long long> m;
int main() {
    cin >> s;
    len = s.length();
    for (long long i = 0; i < len; i++) {
        long long num = s[i]+0;
        m[num]++;
    }
    for (long long i = 0; i < 26; i++) {
        if (m[i+97] > 1) {
            total += (m[i+97]*(m[i+97]-1))/2;
        }
    }
    long long comb = (len*(len-1))/2;
    long long result = comb - total + 1;
    cout << result;
    return 0;
}