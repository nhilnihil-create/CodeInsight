#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int c[h][w];
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int i; int j;
    int tmp=0; int color=1;
    for(i=0;i<h;i++){
        if(i%2==0){
            for(j=0;j<w;j++){
                c[i][j]=color;
                tmp++;
                if(tmp==a[color-1]){
                    color++;
                    tmp=0;
                }
            }
        }
        else{
            for(j=w-1;j>=0;j--){
                c[i][j]=color;
                tmp++;
                if(tmp==a[color-1]){
                    color++;
                    tmp=0;
                }
            }
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w-1;j++)cout << c[i][j] << " ";
        cout << c[i][w-1] << endl;
    }
}