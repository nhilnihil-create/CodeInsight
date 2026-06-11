#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>

using namespace std;
const long long INF = 1LL << 60;
typedef long long int lli;

int main()
{
    // Input numbers
    string a, b, c;
    cin >> a >> b >> c;

    int len[3] = {(int)a.length(), (int)b.length(), (int)c.length()};
    const char *ac[] = {a.c_str(), b.c_str(), c.c_str()};
    int i[3] = {0, 0, 0};

    int turn = 0;
    for (;;) {
        if (len[turn] > i[turn]) {
            char t = ac[turn][i[turn]];
            i[turn]++;
            turn = (t == 'a') ? 0 : (t == 'b') ? 1 : 2;
        } else {
            break;
        }
    }

    char res = (turn == 0) ? 'A' : (turn == 1) ? 'B' : 'C';

    cout << res << endl;
    return 0;
}