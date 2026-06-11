#include <bits/stdc++.h>

using namespace std;

int cnt[30];

int main()
{
    string s;
    cin >> s;
    s.pop_back();
    for(int i = 0; i < 200 ; ++i){
        // cout << s << endl;
        int n = s.length();
        if(n%2){
            s.pop_back();
            continue;
        }
        string a = s.substr(0,n/2) , b = s.substr(n/2,n/2);
        if(a==b){
            cout << s.length() << endl;
            return 0;
        }else s.pop_back();
    }
    return 0;
}