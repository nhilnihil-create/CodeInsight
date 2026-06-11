#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    string s;
    cin >> s;
    string ans = string(s);
    string temp = s.substr(1,s.length()-2);
    ans = s[0] + to_string(temp.length()) + s[s.length()-1];
    cout << ans << endl;
    return 0;
}
