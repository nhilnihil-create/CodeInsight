#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    string inp;cin >>inp;
    int j =inp.size();
    if(j==1){
        cout << "No";return 0;
    }
    int n=0,s=0,e=0,w=0;
    fo(i,j){
        if(inp[i]=='N'){
            n=1;
        }
        if(inp[i]=='E'){
            e=1;
        }
        if(inp[i]=='W'){
            w=1;
        }
        if(inp[i]=='S'){
            s=1;
        }
    }
    if(n&&w&&e&&s){
        cout << "Yes";return 0;
    }
    else if((n&&s&&e)||(n&&s&&w)||(w&&s&&e)||(w&&n&&e)){
        cout << "No";return 0;
    }
    else if((n&&s)||(e&&w)){
        cout << "Yes";return 0;
    }
    else{
        cout << "No";return 0;
    }
}


