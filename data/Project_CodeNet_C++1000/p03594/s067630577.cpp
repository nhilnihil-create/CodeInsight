#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int h,w,d;
int mp[2003][2003];
int main(){
    cin>>h>>w>>d;
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=2000;j++){
            int tmp=((i/(d))%2)*2+(j/(d))%2;
            mp[i][j]=tmp;
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int x=i+j+500,y=i-j+500;
            if(mp[x][y]==0){
            	cout<<"R";
			}else if(mp[x][y]==1){
            	cout<<"Y";
			}else if(mp[x][y]==2){
            	cout<<"G";
			}else{
            	cout<<"B";
			}
        }
        cout<<endl;
    }
    return 0;
}