#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n);i++)
using namespace std;

int main(){
    int h, w;  cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin >> a[i][j];
    }
    
    for(int i=-1; i<=h; i++){
        if(i==-1 || i == h){
           for(int j=0; j<=w+1; j++) printf("#");
           printf("\n"); 
        }else{
            printf("#");
            rep(j,w) printf("%c",a.at(i).at(j));
            printf("#\n");
        }
    }
    return 0;
}