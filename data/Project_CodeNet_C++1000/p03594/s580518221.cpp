#include <bits/stdc++.h>

using namespace std;

const string color = "RYGB";

int H,W,d;

int main() {
    cin>>H>>W>>d;
    for (int h=0;h<H;h++) {
        for (int w=0;w<W;w++) {
            int d1 = h+w;
            int d2 = h-w+W-1;
            int num = d1/d % 2 * 2 + d2/d % 2  * 3;
            cout << color[num%4];
        }
    cout<<endl;
    }
}


