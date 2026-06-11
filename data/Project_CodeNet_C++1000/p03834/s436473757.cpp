#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef long double ld;

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(s[i]==','){
                cout<<" ";
            }
            else{
                cout<<s[i];
            }
        }
    }
}