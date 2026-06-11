#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i;
    for(i=0;i<s.length();i++){
        if(s[i]==' '){
            cout<<"A"<<s[i+1]<<"C"<<endl;
            break;
        }
    }
    return 0;
}
