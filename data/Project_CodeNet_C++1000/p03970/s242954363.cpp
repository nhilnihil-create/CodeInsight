#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(void) {
    string s;
    cin >> s;
    string ref = "CODEFESTIVAL2016";
    int count = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] != ref[i])count ++;
    }
    cout << count << endl;
}
