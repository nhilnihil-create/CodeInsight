#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;cin>>S;
    int A,Z,ans;A=200001;Z=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='A'){
            A=i;
            break;
        }
    }
    for(int i=S.size()-1;i>=0;i--){
        if(S[i]=='Z'){
            Z=i;
            break;
        }
    }
    cout<<Z-A+1<<endl;
    return 0;
}