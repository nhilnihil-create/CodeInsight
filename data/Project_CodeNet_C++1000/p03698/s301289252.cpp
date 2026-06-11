#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string ans = "";
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i - 1] == s[i]){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}
