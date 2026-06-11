#include <iostream>
#include <vector>
using namespace std;
int main(void){
    long long int x, y;
    cin>>x>>y;
    if(x>0&&y>0){
        long long int ans=abs(y-x);
        if(x>y) ans+=2;
        cout<<ans<<endl;
    }else if(x>0&&y<0){
        if(x!=abs(y)) cout<<abs(abs(y)-x)+1<<endl;
        if(x==abs(y)) cout<<1<<endl;
    }else if(x<0&&y>0){
        if(abs(x)!=y) cout<<abs(abs(x)-y)+1<<endl;
        if(abs(x)==y) cout<<1<<endl;
    }else if(x<0&&y<0){
        if(abs(x)>abs(y)){
            cout<<abs(x)-abs(y);
        }else if(abs(x)<abs(y)){
            cout<<2+abs(y)-abs(x);
        }else{
            cout<<0<<endl;
        }
    }else if(x==0&&y>0){
        cout<<y<<endl;
    }else if(x==0&&y<0){
        cout<<abs(y)+1<<endl;
    }else if(x>0&&y==0){
        cout<<x+1<<endl;
    }else if(x<0&&y==0){
        cout<<abs(x)<<endl;
    }else if(x==0&&y==0){
        cout<<0<<endl;
    }
}
