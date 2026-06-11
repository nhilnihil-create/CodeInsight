#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        string N; cin >> N;
        cout << "ABC";
        int len = N.length();
        if (len == 2) cout << "00" << N << endl;
        else if (len == 1) cout << "0" << N << endl;
        else cout << N << endl;


}
