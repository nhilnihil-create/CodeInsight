#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;

    vector<vector<char>> c(h,vector<char>(w));
    vector<vector<char>> d(h*2,vector<char>(w));
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>c[i][j];
            d[i*2][j]=c[i][j];
            d[i*2+1][j]=c[i][j];
        }
    }

    for(int i=0; i<h*2; i++){
        for(int j=0; j<w; j++){
            cout<<d[i][j];
            if(j==w-1){
                cout<<endl;
            }
        }
    }
}