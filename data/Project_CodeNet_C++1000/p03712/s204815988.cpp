#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> s;
    string sharp(W+2,'#');
    s.push_back(sharp);
    for(int i=0; i<H; i++){
        string tmp;
        cin >> tmp;
        s.push_back('#'+tmp+'#');
    }
    s.push_back(sharp);

    for(int i=0; i<H+2; i++){
        cout << s.at(i) <<endl;
    }
}