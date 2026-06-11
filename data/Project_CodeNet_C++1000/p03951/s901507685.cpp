#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i=0,j=0,onajimoji;
    cin >> n;
    string s,t;
    cin >> s >> t;
    for(i=0;i<n;i++){
        onajimoji=0;
        for(j=0;j<n-i;j++){ 
            if(s[i+j]==t[j])onajimoji++;
        }
        if(onajimoji==n-i)break;
    }
    cout << 2*n - onajimoji << endl;
    return 0;
}