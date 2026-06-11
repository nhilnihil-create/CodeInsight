#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string a, b;
    cin >> a >> b;
    if (a.size() == b.size()){
        if (a > b) {
            cout << "GREATER" <<endl;
            return 0;
        } 
        else if (b > a) {
            cout << "LESS" << endl;
            return 0;
        }
        else {
            cout << "EQUAL" << endl;
            return 0;
        }
    }
    else if (a.size() > b.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    else {
        cout << "LESS" << endl;
    }
    return 0;
}