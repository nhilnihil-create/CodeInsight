#include<bits/stdc++.h>
using namespace std;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    for(int i = sy;i <ty; i++){
        cout << "U";
    }
    for(int i = sx;i <tx; i++){
        cout << "R";
    }
    for(int i = ty;sy < i; i--){
        cout << "D";
    }
    for(int i = tx;sx < i; i--){
        cout << "L";
    }
    cout << "L";

    for(int i = sy;i <=ty; i++){
        cout << "U";
    }
    for(int i = sx;i <=tx; i++){
        cout << "R";
    }
    cout << "D";
    cout << "R";
    for(int i = ty;sy <= i; i--){
        cout << "D";
    }
    for(int i = tx;sx <= i; i--){
        cout << "L";
    }
    cout << "U" << endl;
}