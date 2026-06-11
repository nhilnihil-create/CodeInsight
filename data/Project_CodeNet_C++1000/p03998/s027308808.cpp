#include <bits/stdc++.h>
using namespace std;

int main(){
    string s[3];
    for(int i=0; i<3; i++) cin>>s[i];

    int cur = 0;
    char ans;

    while(1){
        if(s[cur].size() == 0){
            ans = 'A' + cur;
            break;
        }
        char c = s[cur][0];
        s[cur].erase(0,1);
        int dif = 'a' - 'A';
        c -= dif;
        cur = c - 'A';
    }

    cout<<ans<<endl;

    return 0;
}