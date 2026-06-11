#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    map<int,bool>m;
    bool chk = true;
    for(int i=0;i<s.length();i++){
        int num = (int)(s[i]-'a');
        if(m[num]){
            chk=false;
        }else{
            m[num] = true;
        }
    }
    if(chk)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}