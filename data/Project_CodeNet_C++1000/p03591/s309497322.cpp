#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin>>a;
    if(a.size()<=3){
        cout<<"No"<<endl;
    }else{
         if (a.at(0)=='Y' && a.at(1)=='A' && a.at(2)=='K' && a.at(3)=='I') {
               cout<<"Yes"<<endl;
           }else{
               cout<<"No"<<endl;
           }
    }
    return 0;
}