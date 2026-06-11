#include<iostream>
#include<vector>
using namespace std;

int main(){
    int w,h,n;
    cin>>w>>h>>n;
    int l=0,b=0;
    for(int i=0;i<n;i++){
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1) l=max(x,l);
        if(a==2) w=min(x,w);
        if(a==3) b=max(y,b);
        if(a==4) h=min(y,h);
    }
    if(w-l<0||h-b<0) cout<<0<<endl;
    else cout<<max(0,(w-l)*(h-b))<<endl;
}