#include <iostream>
#include <string>
using namespace std;

int main(){
    int count=0;
    string s;
    string h="CODEFESTIVAL2016";
    cin>>s;
    for (int i=0; i<=15; i++) {
        if(s.at(i)!=h.at(i)){
            count++;
        }
    }
    cout<<count<<endl;
    }