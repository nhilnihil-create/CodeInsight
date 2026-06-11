#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n;
string s;
map<pair<string, string>, long long> mm;
long long ans;
string s1, s2;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a <= c && c <= b)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
