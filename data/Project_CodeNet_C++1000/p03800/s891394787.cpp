#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
char ans[MAXN];
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s='#'+s;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            if(i==1){
                ans[1] = 'W';
            }else{
                ans[1] = 'S';
            }
            if(j==1){
                ans[2] = 'S';
            }else{
                ans[2] = 'W';
            }
            for(int x=2;x<n;x++){
                if(ans[x] == 'S'){
                    if(s[x] == 'o'){
                        ans[x+1] = ans[x-1];
                    }else{
                        if(ans[x-1] == 'S'){
                            ans[x+1] = 'W';
                        }else{
                            ans[x+1] = 'S'; 
                        }
                    }
                }else{
                    if(s[x] == 'x'){
                        ans[x+1] = ans[x-1];
                    }else{
                        if(ans[x-1] == 'S'){
                            ans[x+1] = 'W';
                        }else{
                            ans[x+1] = 'S'; 
                        }
                    }
                }

            }
            if((s[1] == 'o'  && ans[1] == 'S')||(s[1] == 'x' && ans[1] == 'W')){
                if(ans[2]!=ans[n]){
                    
                    continue;
                }
            }else{
                if(ans[2] == ans[n]){
                    
                    continue;
                }
            }
            if((s[n] == 'o'  && ans[n] == 'S')||(s[n] == 'x' && ans[n] == 'W')){
                if(ans[1]!=ans[n-1]){
                    continue;
                }
            }else{
                if(ans[1] == ans[n-1]){
                   // cout<<i<<" "<<j<<" "<<ans[2]<<" "<<ans[n]<<endl;
                    continue;
                }
            }
            for(int x=1;x<=n;x++){
                cout<<ans[x];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}