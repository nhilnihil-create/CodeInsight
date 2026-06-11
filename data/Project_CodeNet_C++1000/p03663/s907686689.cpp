#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <cstdlib>

using namespace std;

string num = "";

char ask(string str)
{
	char ch;
    cout << "? " << str << endl << flush;
    cin >> ch;
    return ch;
}

void answer(string str)
{
    cout << "! " << str << endl << flush;
    exit(0);
}

bool check(char digit)
{
    if (digit == '9') return true;
    string tmp = num + digit;
    tmp.append(15 - tmp.size(), '9');
    bool res = (ask(tmp) == 'Y');
//    cerr << tmp << ": " << res << endl;
    return res;
}

int getceil(char l, char r)
{
    while (r > l) {
        char m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m+1;
//        cerr << l << ' ' << r << endl;
    }
    return r;
}

int solve()
{
	char ch = ask("1000000000000001");
	if (ch == 'Y') {
        string str = "2";
        while (ask(str) == 'N') str += "2";
        answer("1" + string(str.size() - 1, '0'));
        return 0;
	}

    string str = "1";
    while (ask(str) == 'Y') {
		str += '0';
    }
    int numdigits = str.size() - 1;


    num += getceil('1', '9');
    for (int i = 1; i < numdigits; ++i) {
        num += getceil('0', '9');
    }
    answer(num);
	return 0;
}

int main()
{
    return solve();
}
