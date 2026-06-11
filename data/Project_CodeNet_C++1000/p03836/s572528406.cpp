#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    string S = "";
    for(int i=0; i<dy; i++) S += "U";
    for(int i=0; i<dx; i++) S += "R";
    for(int i=0; i<dy; i++) S += "D";
    for(int i=0; i<dx; i++) S += "L";
    S += "L";
    for(int i=0; i<dy+1; i++) S += "U";
    for(int i=0; i<dx+1; i++) S += "R";
    S += "D";
    S += "R";
    for(int i=0; i<dy+1; i++) S += "D";
    for(int i=0; i<dx+1; i++) S += "L";
    S += "U";
    cout << S << endl;
    return 0;
}