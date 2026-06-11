#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long,int> pp;

int main() {
    int W,H;
    cin >> W >> H;
    vector<pp> p(W+H);
    for(int i=0; i<W+H; i++) {
        long long tmp;
        cin >> tmp;
        p[i] = pp(tmp,i);
    }
    sort(p.begin(), p.end());
    long long a = W + 1;
    long long b = H + 1;
    long long res = 0;
    for(int index=0; index<p.size(); index++) {
        pp e = p[index];
        if(e.second < W) {
            res += e.first * b;
            a--;
        } else {
            res += e.first * a;
            b--;
        }
    }
    cout << res << endl;
}