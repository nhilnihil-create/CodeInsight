#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int sz;
    sz = str.size();
    int mx=0;
    int scr=0;
    for(int i=0; i<sz; i++){
        if(str[i]=='I'){
            scr++;
        }else if(str[i]=='D'){
            scr--;
        }
        mx = max(mx,scr);
    }
    cout << mx << endl;
}


