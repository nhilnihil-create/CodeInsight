#include <bits/stdc++.h>
using namespace std;
int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx, dy = ty - sy;
    string res = "";
    
    for(int i = 0; i < dx; i++) res += "R";
    for(int i = 0; i < dy; i++) res += "U";
    for(int i = 0; i < dx; i++) res += "L";
    for(int i = 0; i < dy; i++) res += "D";
    
    res += "D";
    for(int i = 0; i < dx + 1; i++)res += "R";
    for(int i = 0; i < dy + 1; i++)res += "U";
    res += "L";
    res += "U";
    for(int i = 0; i < dx + 1; i++) res += "L";
    for(int i = 0; i < dy + 1; i++) res += "D";
    res += "R";
    cout << res << endl;
    
}
