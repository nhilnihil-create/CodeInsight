#include<iostream>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int i,j;
    for(i=0;i<w+2;i++)
        cout << '#';
    cout << endl;
    char a[h][w];
    for(i=0;i<h;i++){
        cout << '#';
        for(j=0;j<w;j++){
            cin >> a[i][j];
            cout << a[i][j];
        }
        cout << '#' << endl;
    }
     for(i=0;i<w+2;i++)
        cout << '#';
    cout << endl;
}