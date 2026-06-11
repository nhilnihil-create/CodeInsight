#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> matrix(H, "");
    string aux;
    getline(cin, aux);
    for(int i=0;i<H;i++){
        getline(cin, matrix[i]);
    }
    for(int i=0;i<2*H;i++){
        cout << matrix[i/2];
        cout << "\n";
    }
}