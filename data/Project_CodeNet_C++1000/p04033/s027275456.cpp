#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    int a,b,n,d=0;
    cin>>a>>b;
    if(a<=0&&b>=0)d=1;
    else if(a<0&&b<0)n=b-a+1;
    else n=0;
    if(d)cout<<"Zero"<<endl;
    else if((n%2)==0)cout<<"Positive"<<endl;
    else cout<<"Negative"<<endl;
}