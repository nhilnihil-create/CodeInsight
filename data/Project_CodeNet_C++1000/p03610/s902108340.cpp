#include <iostream>
#include <string>

using namespace std;
int main(void){
    string s;
    cin>>s;
    string result;
    for(int i=0;i<s.size();i=i+2){
        result+=s[i];
    }
    cout<<result<<endl;
    return 0;
}