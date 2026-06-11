#include <iostream>
using namespace std;
int main(void){
    int H, W;
    char X;
    cin >> H >> W;
    for(int i=0;i<W+2;i++){
        cout << "#";
    }
    cout << endl;
    for(int i=0;i<H;i++){
        cout << "#";
        for(int i=0;i<W;i++){
            cin >> X;
            cout << X; 
        }
        cout << "#" << endl;
    }
     for(int i=0;i<W+2;i++){
        cout << "#";
    }
}