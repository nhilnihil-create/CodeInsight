#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    string S;cin>>S;
    for(int i=S.size()-2;i>0;i-=2){
        if(S.substr(0,i/2)==S.substr(i/2,i/2)){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
