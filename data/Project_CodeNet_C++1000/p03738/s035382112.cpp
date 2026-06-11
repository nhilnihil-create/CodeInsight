#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>
#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    boost::multiprecision::cpp_int a, b;
    cin >> a >> b;

    if (a > b) {
        cout << "GREATER" << endl;
    }
    else if (a < b) {
        cout << "LESS" << endl;
    }
    else {
        cout << "EQUAL" << endl;
    }
}