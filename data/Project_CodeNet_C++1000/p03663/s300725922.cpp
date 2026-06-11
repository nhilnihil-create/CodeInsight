#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

// #define LOCAL

#ifdef LOCAL
constexpr long N = 999999999;
#endif

string toStr(long v)
{
    ostringstream oss;
    oss << v;
    return oss.str();
}

long fromStr(const string& s)
{
    istringstream iss(s);
    long v;
    iss >> v;
    return v;
}


bool ask(long n)
{
#ifdef LOCAL
    string sn = toStr(n);
    string sN = toStr(N);
    bool ans = (n <= N && sn <= sN) || (n > N && sn > sN);
    cout << "? " << n << " => " << ans << '\n';
    return ans;
#else
    cout << "? " << n << '\n';
    cout.flush();

    string ans;
    cin >> ans;
    return ans == "Y";
#endif
}

void answer(long n)
{
#ifdef LOCAL
    cout << "! " << n << '\n';
    cout << (n == N ? "CORRECT\n" : "WRONG\n");
#else
    cout << "! " << n << '\n';
    cout.flush();
#endif
}

void detHead(char* sn, int d)
{
    sn[d] = '4';
    bool ans = ask(fromStr(sn));
    if (ans) {
        sn[d] = '2';
        ans = ask(fromStr(sn));
        if (ans) {
            sn[d] = '1';
            ans = ask(fromStr(sn));
            if (ans && d != 0) {
                sn[d] = '0';
                ans = ask(fromStr(sn));
                if (!ans)
                    sn[d] = '1';
            } else if (!ans) {
                sn[d] = '2';
            }
        } else {
            sn[d] = '3';
            ans = ask(fromStr(sn));
            if (!ans)
                sn[d] = '4';
        }
    } else {
        sn[d] = '7';
        ans = ask(fromStr(sn));
        if (ans) {
            sn[d] = '6';
            ans = ask(fromStr(sn));
            if (ans) {
                sn[d] = '5';
                ans = ask(fromStr(sn));
                if (!ans)
                    sn[d] = '6';
            } else {
                sn[d] = '7';
            }
        } else {
            sn[d] = '8';
            ans = ask(fromStr(sn));
            if (!ans)
                sn[d] = '9';
        }
    }
}

bool detTail(char* sn, int lastnz, int last)
{
    if (sn[lastnz] != '9') {
        ++sn[lastnz];
        sn[last] = '\0';
        bool ans = ask(fromStr(sn));
        --sn[lastnz];
        if (ans)
            return true;
        sn[last] = '0';
        return false;
    }

    --sn[lastnz];
    bool ans = ask(fromStr(sn));
    ++sn[lastnz];
    if (ans)
        return false;
    sn[last] = '\0';
    return true;
}

int main()
{
    char sn[12];
    for (int i = 0; i < 11; ++i)
        sn[i] = '9';
    sn[11] = '\0';

    for (int i = 0; i < 10; ++i)
        detHead(sn, i);

    sn[10] = '\0';
    int last = 9;
    int lastnz = 9;
    while (sn[lastnz] == '0')
        --lastnz;

    while (lastnz < last) {
        if (!detTail(sn, lastnz, last)) {
            break;
        }
        --last;
    }

    answer(fromStr(sn));

    return 0;
}
