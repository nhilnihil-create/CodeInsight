#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,j;
    int H,W;
    cin >> H>>W;
    vector<vector<char>> a(H,vector<char>(W));
    vector<vector<char>> o(H+2,vector<char>(W+2));
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin>>a.at(i).at(j);
        }
    }
    for(i=0;i<H+2;i++){
        for(j=0;j<W+2;j++){
            if((i==0 || i==H+1) || (j==0 || j==W+1)){
                o.at(i).at(j) = '#';
                //cout<< i<<j<<'#' <<endl;
            }else{
                o.at(i).at(j) = a.at(i-1).at(j-1);
                //cout<< i<<j<<o.at(i).at(j) <<endl;
            }
        }

    }
    for(i=0;i<H+2;i++){
        for(j=0;j<W+2;j++){
            cout<< o.at(i).at(j) <<flush;
        }
        cout<<endl;
    }
}