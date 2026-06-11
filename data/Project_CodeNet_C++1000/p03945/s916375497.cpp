#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int count = 1;
    char comp = s[0];
    int i;
    for(i=1;i<s.length();i++){
        if(comp!=s[i]){
            comp = s[i];
            count++;
        }
    }
    cout<<count-1;
    return 0;
}