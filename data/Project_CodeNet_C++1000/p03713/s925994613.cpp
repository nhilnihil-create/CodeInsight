#include <iostream>
#include <algorithm>
using namespace std;
long long h,w,ans=1e9,a,b,c;
int main(){
    cin>>h>>w;
    for(int i=0;i<2;i++){
        if(i){
            long long t=h;
            h=w;
            w=t;
        }
        for(int i=1;i<h;i++){
            a=i*w;
            b=max((h-i)*(w/2),((h-i)/2)*w);
            c=h*w-a-b;
            ans=min(max(a,max(b,c))-min(a,min(b,c)),ans);
        }
    }
    cout<<ans;
}
