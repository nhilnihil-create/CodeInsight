
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l=s.length();
    if(s[0]==s[l-1]){
        if(l%2==0){
            cout<<"First"<<endl;
            return 0;
        }
        else{
            cout<<"Second"<<endl;
            return 0;
        }
    }
    else{
        if(l%2==0){
            cout<<"Second"<<endl;
            return 0;
        }
        else{
            cout<<"First"<<endl;
            return 0;
        }
    }
}