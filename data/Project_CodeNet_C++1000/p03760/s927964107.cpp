#include <bits/stdc++.h>
using namespace std;

int main()
{

        string O, E;
        cin >> O >> E;
        int len = O.length() + E.length();
        int oc = 0;
        int ec = 0;
        for (int i = 0; i < len; ++i) {
                if ((i+1) % 2) {
                        cout << O[oc];
                        oc++;
                }
                else {
                        cout << E[ec];
                        ec++;
                }
        }
        cout << endl;



}
