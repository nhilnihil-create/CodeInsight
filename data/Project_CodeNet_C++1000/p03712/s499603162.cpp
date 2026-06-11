#include<bits/stdc++.h>

using namespace std;

int main(){
    /*
    height + 2
    width + 2
    */
    int x,y;
    cin>>x>>y;
    char arr[x+2][y+2];
    for(int i = 0; i < x+2; i++){
        for(int j = 0; j < y+2; j++){
            arr[i][j] = '#';
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin>>arr[i+1][j+1];
        }
    }
    for(int i = 0; i < x+2; i++){
        for(int j = 0; j < y+2; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
