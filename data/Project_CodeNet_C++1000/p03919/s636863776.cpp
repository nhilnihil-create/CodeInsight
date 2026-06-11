#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[45][45];
signed main(){
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(s[i][j]=="snuke"){
                cout<<char(j+'A')<<i+1<<endl;
                return 0;
            }
        }
    }
}