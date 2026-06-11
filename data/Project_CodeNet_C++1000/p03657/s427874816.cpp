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
    int a,b;
    cin >> a >> b;
    if(a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
