#include <iostream>
#include <map>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    map<pair<int,int>, int> mp;
    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;
        for (int x=max(1,b-2); x<=b && x+2<=W; x++) {
            for (int y=max(1,a-2); y<=a && y+2<=H; y++) {
                // (x,y) は左上の頂点
                mp[make_pair(x,y)]++;
            }
        }
    }

    long long a[10];
    for (int i=0; i<10; i++) a[i] = 0;

    long long sum = 0;
    for(const auto m: mp) {
        a[m.second]++;
        sum++;
    }

    // 0だけ
    a[0] = (long long)(H-3+1) * (long long)(W-3+1) - sum;

    for (int i=0; i<10; i++) {
        cout << a[i] << endl;
    }
    return 0;
}