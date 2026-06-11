#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int count_yoko=tx-sx;
    int count_tate=ty-sy;
    for(int i=0;i<count_tate;i++) cout << "U";
    for(int i=0;i<count_yoko;i++) cout << "R";
    for(int i=0;i<count_tate;i++) cout << "D";
    for(int i=0;i<=count_yoko;i++) cout << "L";
    for(int i=0;i<=count_tate;i++) cout << "U";
    for(int i=0;i<=count_yoko;i++) cout << "R";
    cout << "D"; cout << "R";
    for(int i=0;i<=count_tate;i++) cout << "D";
    for(int i=0;i<=count_yoko;i++) cout << "L";
    cout << "U";
    return 0;
}
