#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int g = count(s.begin(), s.end(), 'g');
    int p = s.size() - g;
    cout << (g - p) / 2 << endl;
}