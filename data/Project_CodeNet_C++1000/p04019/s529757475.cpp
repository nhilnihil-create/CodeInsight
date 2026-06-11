#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int N=0,S=0,E=0,W=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='N') {
            N++;
        } else if (s[i]=='S') {
            S++;
        } else if (s[i]=='E') {
            E++;
        } else if (s[i]=='W') {
            W++;
        }
    }
    int flag=0;
    if (N>0&&S>0) {
        flag=1;
    } else if ((N>0&&S==0)||(N==0&&S>0)) {
        cout<<"No"<<endl;
        return 0;
    }
    if (E>0&&W>0) {
        flag=1;
    } else if ((E>0&&W==0)||(E==0&&W>0)) {
        cout<<"No"<<endl;
        return 0;
    }
    if (flag==1) {
        cout<<"Yes"<<endl;
    }
}