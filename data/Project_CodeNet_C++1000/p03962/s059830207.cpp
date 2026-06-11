#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
typedef pair<int, int> P;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    set<int> paint;
    paint.insert(a);
    paint.insert(b);
    paint.insert(c);
    out(paint.size());
}
