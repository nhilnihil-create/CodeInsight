#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int area1=a*b;
    int area2=c*d;
    cout<<max(area1,area2);
}