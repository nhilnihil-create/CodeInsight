#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <deque>
#include<sstream>

using namespace std;
typedef long long int lli;

const int INF = 100100100;

int main()
{
    string line, s;
    getline(cin, line);
    istringstream iss(line);
    lli begin = -1, end = -1;

    char c;
    int i = 1;
    deque<char> v;
    while (iss >> c) {
        if(v.size() >= 3) v.pop_front();
        v.push_back(c);

        if (v.size() == 2) {
            if (v[0] == v[1]) {
                begin = i - 1;
                end = i;
                break;
            }
        }

        if(v.size() >= 3) {
            if ((v[0] == v[1]) | (v[1] == v[2]) | (v[0] == v[2])) {
                begin = i - 2;
                end = i;
                break;
            }
        }

        i++;

    }

    cout << begin << " " << end << endl;
    return 0;
}