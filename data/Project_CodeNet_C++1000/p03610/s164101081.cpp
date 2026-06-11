#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    string S;
    for(int i=0;i<s.size();i++){
        if (i%2==0) S = S+s[i];
    }
    cout<<S<<endl;
}