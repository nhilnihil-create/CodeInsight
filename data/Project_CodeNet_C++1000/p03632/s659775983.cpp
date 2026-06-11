#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int start=max(a,c);
    int end=min(b,d);
    int total=end-start;
    if(total<0)
    total=0;
    cout<<total;
}