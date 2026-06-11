#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int p = 0;
    for(int i = 0; i < S.length(); i++)if(S[i]=='p')p++;
    cout<<S.length()/2-p<<endl;
}