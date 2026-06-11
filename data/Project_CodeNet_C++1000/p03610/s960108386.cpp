#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    string ans;

    for(long long i = 0; i < s.size(); i++){
        if(i % 2 == 0) ans.push_back(s[i]);
    }

    cout << ans << endl;
    return 0;
}