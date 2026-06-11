#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool can_make=true;
    int ind=0;
    while(can_make&&ind<s.size()-1){
        if(s.substr(ind,5)=="dream"){
            ind+=5;
            if(s.substr(ind,2)=="er"&&s.substr(ind,5)!="erase"){
                ind+=2;
            }
        }else if(s.substr(ind,5)=="erase"){
            ind+=5;
            if(s.substr(ind,1)=="r"){
                ind+=1;
            }
        }else{
            can_make=false;
        }
    }
    if(can_make){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}