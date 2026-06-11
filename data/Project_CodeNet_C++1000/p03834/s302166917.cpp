#include <bits/stdc++.h>
using namespace std;
int main(void){
    int i;
    string str;
    cin>>str;
    for(i=0; i<str.length(); i++){
        if(str[i]==','){
            cout<<" ";
        }else{
            cout<<str[i];
        }
    }
    cout<<endl;
    return 0;
}
