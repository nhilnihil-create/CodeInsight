#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    /*重なりを求める。c-dを固定しa-bを動かして範囲による
    場合分けをするのが数学的な解き方だが、
    今回は配列を使って解くことにする。*/
    int time[101]={0};
    for (int i=a; i<b; i++) time[i] += 1;
    for (int i=c; i<d; i++) time[i] += 1;
    
    int count = 0;
    for (int i=0; i<101; i++) {
        if (time[i] == 2) count++;
    }
    cout << count << endl;
    return 0;
}