#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {    
    string s,t;
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    if(t == s) puts("Yes");
    else puts("No");
    return 0;
}
