#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][2],c[m][2];
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<m;i++){
        cin>>c[i][0]>>c[i][1];
    }
    for(int i=0;i<n;i++){
        int tmp=2e9,ans,len;
        for(int j=0;j<m;j++){
            len=abs(a[i][0]-c[j][0])+abs(a[i][1]-c[j][1]);
            if(len<tmp){
                tmp=len;
                ans=j+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}