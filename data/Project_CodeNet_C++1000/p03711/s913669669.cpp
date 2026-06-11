#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,i,j;
    int a[]={1,3,5,7,8,10,12},b[]={4,6,9,11};
    cin>>x>>y;
    if(x==2||y==2) cout<<"No";
    else {
        for(i=0;i<6;i++){
            for(j=i+1;j<7;j++)
                if(x==a[i]&&y==a[j]){
                    cout<<"Yes"; return 0;
                }
        }
        for(i=0;i<3;i++){
            for(j=i+1;j<4;j++)
                if(x==b[i]&&y==b[j]){
                    cout<<"Yes"; return 0;
                }
        }
        cout<<"No";
    }
	return 0;
}