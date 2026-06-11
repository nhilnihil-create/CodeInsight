#include <iostream>
using namespace std;

int main(){
    int h,w;
    char a[100][100];
    cin>>h>>w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<h+2;++i){
        if(i==0||i==h+1){
            for(int j=0;j<w+2;++j){
                cout<<'#';
            }
        }
        else{
            for(int j=0;j<w+2;++j){
                if(j==0||j==w+1){
                    cout<<'#';
                }
                else{
                    cout<<a[i-1][j-1];
                }
            }
        }
    cout<<endl;
    }
}
