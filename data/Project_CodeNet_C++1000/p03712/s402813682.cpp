#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    //input
    int h,w;cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w ; j++){
            cin >> a[i][j];
        } 
    }

    //compute

    //output
    for(int i = 0; i < w + 2; i++) {
        cout << '#';
    }

    cout << endl;        

    for(int i = 0; i < h; i++) {
        cout << '#';
        for(int j = 0; j < w; j++) {
            cout << a[i][j];
            if(j == w -1){
                cout << '#' << endl;
            }
        }
    } 

    for(int i = 0; i < w + 2; i++) {
        cout << '#';
    }

    cout << endl;      
}