#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b;
    cin>>a>>b;
    if (a>0&&b>0) {
        cout<<"Positive"<<endl;
    } else if ( (a<=0&&0<=b) || (a>=0&&b<=0) ) {
        cout<<"Zero"<<endl;
    } else if (a<0&&b<0) {
        long long int tmp=abs(b)-abs(a);
        if (tmp%2==0) {
            cout<<"Negative"<<endl;
        } else {
            cout<<"Positive"<<endl;
        }
    }
}