#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>
#include <map>

using namespace std;
typedef long long int lli;

const int INF = 100100100;

int main()
{
    string line, s;
    getline(cin, line);
    istringstream iss(line);

    char c;
    map<char, int> w;
    while (iss >> c) {
        auto itr = w.find(c);
        if( itr != w.end() ) {
            w[c]++;
        } else {
            w[c] = 1;
        }
    }

    bool is_beautiful = true;
    for(auto itr = w.begin(); itr != w.end(); ++itr) {
        if (itr->second % 2 != 0) {
            is_beautiful = false;
            break;
        }
    }

    string ans = (is_beautiful) ? "Yes" : "No";

    cout << ans << endl;
    return 0;
}