#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int a, b;
    a = s.find('A');
    b = s.rfind('Z');
    cout << b - a + 1 << endl;
}
   