#include <iostream>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    char img[h][w];
    for(int r=0;r<h;r++){
        for(int c=0;c<w;c++){
            cin>>img[r][c];
        }
    }
    for(int r=0;r<2*h;r++){
        for(int c=0;c<w;c++){
            cout<<img[(r+1+1)/2-1][c];
        }
        cout<<endl;
    }
    return 0;
}