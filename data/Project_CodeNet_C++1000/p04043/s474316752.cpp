#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c;
    int count5=0, count7=0;
    while(cin>>a){
        if(a==5)
        count5++;
        if(a==7)
        count7++;
    }
    
    if(count5==2 && count7==1)
        cout<<"YES";
    else
        cout<<"NO";
}
