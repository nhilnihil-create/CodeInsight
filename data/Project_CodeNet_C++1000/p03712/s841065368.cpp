#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h+1, vector<char>(w+1));
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> a.at(i).at(j);
        }
    }

    for(int i=0; i<=h+1; i++){
        for(int j=0; j<=w+1; j++){
            if(i==0 || i==h+1 || j==0 || j==w+1) cout << '#';
            else cout << a.at(i).at(j);
        }
        cout << endl;
    }
}