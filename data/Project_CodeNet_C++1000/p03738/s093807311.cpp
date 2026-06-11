#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //char s1[120], s2[120];
    string s1, s2;
    cin >> s1 >> s2;
    int len1, len2;
    len1 = s1.length();
    len2 = s2.length();
    if(len1>len2){
        cout << "GREATER\n";
    }
    else if(len1<len2){
        cout << "LESS\n";
    }
    else{
        if(s1>s2) cout << "GREATER\n";
        else if(s1<s2) cout << "LESS\n";
        else cout << "EQUAL\n";
    }
    return 0;
}