#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
 
int main() {
    int H, W;
    cin >> H >> W;

    // input
    string str((H+2)*(W+2), '#');
    for(int n1=1; n1<=H; n1++){
        for(int n2=1; n2<=W; n2++){
            cin >> str.at(n1*(W+2)+n2);
        }
    }
    // output
    for(int n1=0; n1<H+2; n1++){
        for(int n2=0; n2<W+2; n2++){
            cout << str.at(n1*(W+2)+n2);
        }
        cout << endl;
    }
    return 0;
}