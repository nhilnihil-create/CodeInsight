#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    int g=0,p=0,ans=0;
    cin >> S;
    for(int i=0;i<S.size();i++){
        if(p<g && S[i]=='g'){
            ans++;
            p++;
        }else if(p<g && S[i]=='p'){
            p++;
        }else if(S[i]=='g'){
            g++;
        }else{
            ans--;
            g++;
        }
    }

    cout << ans << endl;
}