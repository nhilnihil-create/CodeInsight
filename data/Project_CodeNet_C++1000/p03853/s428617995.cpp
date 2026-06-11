#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{   
    int H, W;
    cin >> H >> W;
    char a[H][W];
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            cin >> a[i][j];
        }
    }
    
    char ans[2*H][W];
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            ans[2*i][j] = a[i][j];
            ans[2*i+1][j] = a[i][j];
        }
    }
    
    for(int i=0; i<2*H; ++i){
        for(int j=0; j<W; ++j){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}