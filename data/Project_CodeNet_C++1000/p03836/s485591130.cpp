#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];

int main() {
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx-sx;
    int dy = ty-sy;
    
    cout << string(dy,'U') << string(dx,'R');
    cout << string(dy,'D') << string(dx,'L');
    cout << 'L' << string(dy+1,'U') << string(dx+1,'R') << 'D';
    cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U' << endl;
    
   return 0;
}
