#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s[0]==s[s.length()-1]){
        if(s.length()&1)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    else{
        if(s.length()&1)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}