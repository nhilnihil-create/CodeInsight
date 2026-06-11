#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> line(H+2);
    for (int i=1; i<=H; i++){
        cin >> line[i];
        line[i] = "#" + line[i] + "#";
    }
    for (int i=0; i<W+2; i++){
        line[0] += "#";
        line[H+1] += "#";
    }
    for (int i=0; i<=H+1; i++){
        cout << line[i] << endl;
    }
    return 0;
}