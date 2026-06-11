#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string Sa, Sb, Sc; cin >> Sa >> Sb >> Sc;
    int Ai = 0,  Bi= 0, Ci = 0;
    char tmp = 'a';
    while (1)
    {
        if (tmp=='a') {
            if (Ai==Sa.size()) {cout << 'A' << endl; break;}
            tmp = Sa[Ai], Ai++;
        }
        if (tmp=='b') {
            if (Bi==Sb.size()) {cout << 'B' << endl; break;}
            tmp = Sb[Bi], Bi++;
        }
        if (tmp=='c') {
            if (Ci==Sc.size()) {cout << 'C' << endl; break;}
            tmp = Sc[Ci], Ci++;
        }
    }
    return 0;
}
