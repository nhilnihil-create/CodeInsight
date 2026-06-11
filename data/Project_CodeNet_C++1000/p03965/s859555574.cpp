// AtCoDeerくんと変なじゃんけん
#include <iostream>
#include <string>
using namespace std;
typedef long long INT;

string s;

int main(){
    cin>>s;
    INT p=s.size()/2;
    for(INT i=0;i<s.size();i++){
        if(s[i]=='p') p--;
    }
    cout<<p<<endl;
}