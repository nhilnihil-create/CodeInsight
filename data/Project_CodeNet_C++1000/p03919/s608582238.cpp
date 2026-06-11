#include <iostream>
#include <string>
using namespace std;
    int main(){
    int H,W;
    cin >> W >> H;
    string S[27][27];
    for(int x=0; x<W; x++){
        for(int y=0; y<H; y++){
            cin >> S[x][y];
            if(S[x][y]=="snuke"){
                cout << (char)(y+'A') << x+1 << endl;
            }
        }
    }
    return 0;
    }