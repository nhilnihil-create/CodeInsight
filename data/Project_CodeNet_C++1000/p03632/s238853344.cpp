#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b<c ||d<a) out(0);
    else{
        int start = max(a, c);
        int last = min(b, d);
        out(last-start);
    }
}