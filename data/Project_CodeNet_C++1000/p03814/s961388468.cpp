#include <iostream>
using namespace std;
int main() {
    string s;
    int start,end;
    cin>>s;
    for(int i=0;i<s.length();i++){
       if(s[i]=='A'){
            start=i;
            break;
        }}
        for(int i=0;i<s.length();i++){
         if(s[i]=='Z'){
            end=i;
        }
    }
    cout<<(end-start)+1;
    return 0;
}
