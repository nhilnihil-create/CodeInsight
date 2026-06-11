#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    vector<vector<char>>a(1000,vector<char>(1000));
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(int j=0;j<w+2;j++){
            cout<<'#'<<flush;
        }
        cout<<endl;
    for(int i=0;i<h;i++){
        cout<<'#'<<flush;
        for(int j=0;j<w;j++){
            cout<<a[i][j]<<flush;
        }
        cout<<'#'<<endl;
    }
    for(int j=0;j<w+2;j++){
            cout<<'#'<<flush;
        }
        cout<<endl;
    return 0;
}
