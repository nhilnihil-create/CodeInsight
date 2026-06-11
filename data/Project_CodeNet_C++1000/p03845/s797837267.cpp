#include <iostream>
using namespace std;
int main(void){
    int n,m,p,x,sum;
    int t[100]={};
    cin>>n;
    for(int z=0;z<n;z++){
        cin>>t[z];
    }
    cin>>m;
    for(int z=0;z<m;z++){
        cin>>p>>x;
        for(int y=0;y<n;y++){
            if(y==p-1){
                sum+=x;
                //cout<<"d0";
            }else{
                sum+=t[y];
            }
            //cout<<p<<" x  ";
            //cout<<t[y]<<" ty  ";
        }
        cout<<sum<<endl;
        sum=0;
    }
}