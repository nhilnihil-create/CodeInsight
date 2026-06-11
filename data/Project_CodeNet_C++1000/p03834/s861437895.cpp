#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<19;i++){
        if(i==5 || i==13) cout<<' ';
        else cout<<s[i];
    }
    cout << "\n";
    return(0);
}