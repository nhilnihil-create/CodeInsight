#include<bits/stdc++.h>
using namespace std;
int cut(int h,int w){
    int p1,p2,p3;
    if(h%2==0 && w%3==1)p1=w/3*h,p2=h/2*(w-w/3),p3=p2;
    if(h%2==0 && w%3==2)p1=(w/3+1)*h,p2=h/2*(w-w/3-1),p3=p2;
    if(h%2==1 && w%3==1)p1=w/3*h,p2=h/2*(w-w/3),p3=p2+w-w/3;
    if(h%2==1 && w%3==2)p1=(w/3+1)*h,p2=h/2*(w-w/3-1),p3=p2+w-w/3-1;
    return max({p1,p2,p3})-min({p1,p2,p3});
}
int main(){
    int h,w;
    cin>>h>>w;
    if(h%3==0 || w%3==0)cout<<"0"<<endl;
    else cout<<min({h,w,cut(h,w),cut(w,h)})<<endl;
    return 0;
}