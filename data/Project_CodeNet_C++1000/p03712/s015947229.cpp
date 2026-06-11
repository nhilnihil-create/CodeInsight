#include <bits/stdc++.h>
using namespace std;

int main(void){
    int H,W;cin>>H>>W;
    char A[H+2][W+2];
    for(int i=0;i<H+2;i++){
        for(int l=0;l<W+2;l++){
            if(i==0||i==H+1||l==0||l==W+1){
                A[i][l]='#';
            }
            else{
                cin>>A[i][l];
            }
        }
    }
    for(int i=0;i<H+2;i++){
        for(int l=0;l<W+2;l++){
            cout<<A[i][l];
        }
        cout<<endl;
    }
    return 0;
}