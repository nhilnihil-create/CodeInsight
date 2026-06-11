#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    int cnt = 0;
    cin >> s1;
    s2 = "CODEFESTIVAL2016";
    for(int i=0;i<s1.size();i++){
        if (s1.at(i) != s2.at(i)){
            cnt += 1;
        }
    }
    cout << cnt << endl;

}