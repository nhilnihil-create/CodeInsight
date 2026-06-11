#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s[3];
    cin>>s[0]>>s[1]>>s[2];
    int i=0;
    int n[3]; n[0]=0; n[1]=0; n[2]=0;
    while(true){
        if(n[i]==s[i].size()){
            char ans='A'+i;
            cout<<ans<<endl;
            return 0;
        }
        char t=s[i][n[i]];
        n[i]++;
        if(t=='a'){
            i=0;
        }else if(t=='b'){
            i=1;
        }else{
            i=2;
        }
    }

}
