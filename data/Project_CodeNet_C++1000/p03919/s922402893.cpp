#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int h,w;
    cin>>h>>w;
    char c[26];
    for(char i='A';i<='Z';i++){
        c[i-'A']=i;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            string a;
            cin>>a;
            if(a=="snuke"){
                cout<<c[j]<<i+1<<endl;
            }
        }
    }
}
