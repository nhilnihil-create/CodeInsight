#include <iostream>
using namespace std;

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    for(int i=(n-1)/2;i>0;i--){
        if (s.substr(0,i)==s.substr(i,i)){
            cout<<i*2;
            exit(0);
        }
    }    
}
