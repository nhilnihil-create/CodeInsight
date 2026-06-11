#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,n;
    cin>>h>>w>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int c=0;
    int x[h][w];
    for(int i=0;i<h;i++){
        if(i%2==0){
            for(int j=0;j<w;j++){
                x[i][j]=c+1;
                a[c]--;
                if(a[c]==0)c++;
            }
        }
        else {
            for(int j=w-1;j>=0;j--){
                x[i][j]=c+1;
                a[c]--;
                if(a[c]==0)c++;
            }
        }
    }
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cout<<x[i][j]<<endl;
    return 0;
}