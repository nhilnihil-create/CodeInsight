#include<iostream>
#include<map>
using namespace std;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int p = tx - sx;
    int q = ty - sy;
    string ans;
    for (int i=0; i<p; i++) ans += "R";
    for (int i=0; i<q; i++) ans += "U";
    for (int i=0; i<p; i++) ans += "L";
    for (int i=0; i<q; i++) ans += "D";

    ans += "D";
    for (int i=0; i<p+1; i++) ans += "R";
    for (int i=0; i<q+1; i++) ans += "U";
    ans += "L";
    ans += "U";
    for (int i=0; i<p+1; i++) ans += "L";
    for (int i=0; i<q+1; i++) ans += "D";
    ans += "R";
    cout << ans << endl;
    return 0;
}