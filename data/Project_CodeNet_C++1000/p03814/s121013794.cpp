#include <iostream>
#include <regex>
using namespace std;
int main() {
   string a;
   cin >> a;

    smatch m;
    regex_search(a, m, regex("A.*Z"));
    cout << m.length() << endl;
}
