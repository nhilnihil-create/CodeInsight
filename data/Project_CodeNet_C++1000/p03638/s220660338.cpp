#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int h,w,n,a[100010]={},c[110][110];
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool go=true;
    int k=1;
    for(int i=0;i<h;i++){
        if(go){
            for(int j=0;j<w;j++){
                c[i][j]=k;
                a[k]--;
                if(a[k]==0) k++;
            }
            go=false;
        }
        else{
            for(int j=w-1;j>=0;j--){
                c[i][j]=k;
                a[k]--;
                if(a[k]==0) k++;
            }
            go=true;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}