#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int b,c=1,kun=0;
    int a[100001]={};
    cin>>b;
    for(int z=1;z<b+1;z++){
        cin>>a[z];
    }
    while(1){
        if(b<0){
            cout<<-1<<endl;
            break;
        }
        c=a[c];
        //cout<<c<<endl;
        if(c==2){
            cout<<kun+1<<endl;
            break;
        }
        kun++;
        b--;
    }
}
