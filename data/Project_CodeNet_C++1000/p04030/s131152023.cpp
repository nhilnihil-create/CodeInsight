#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main (void){ 
    string s;
    string result = "";
    vector <string> v(10);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        v[i] += s[i];
        if (v[i] == "0") {
            result += "0";
        } else if (v[i] == "1") {
            result += "1";
        } else {
            if (result.empty()) {

            } else {
                result.pop_back();
            }
        }
    }
    cout << result << endl;
    return 0;
}