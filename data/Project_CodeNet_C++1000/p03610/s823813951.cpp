#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    for (int i = 0;i < s.size();i++){
        if (i%2 == 0) cout << s[i];
    }
    cout << endl;
    return 0;
}