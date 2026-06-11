#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a<=0&&0<=b)cout<<"Zero"<<endl;
    else if(a>0||abs(a-min(b,-1)+1)%2==0)cout<<"Positive"<<endl;
    else cout<<"Negative"<<endl;
}