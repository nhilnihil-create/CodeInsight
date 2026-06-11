#include <bits/stdc++.h>
#define pai 3.14159265
using namespace std;

int main(void){
    int N;cin>>N;
    string S;cin>>S;
    int ans=0;
    int tmp=0;
    for(int i=0;i<N;i++){
        if(S[i]=='I'){
            tmp++;
        }
        if(S[i]=='D'){
            tmp--;
        }
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}