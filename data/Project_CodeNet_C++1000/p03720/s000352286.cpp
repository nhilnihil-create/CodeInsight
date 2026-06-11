#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,d;
    int e[55]={};
    cin>>a>>b;
    for(int z=0;z<b;z++){
        cin>>c>>d;
        e[c]++;
        e[d]++;
    }
    for(int z=1;z<a+1;z++){
        cout<<e[z]<<endl;
    }
}
