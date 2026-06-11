#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}