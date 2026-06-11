#include<bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    int n=0, w=0, s=0, e=0;
    for(int i=0; i<S.length(); i++){
        if(S.at(i)=='N') n++;
        if(S.at(i)=='W') w++;
        if(S.at(i)=='S') s++;
        if(S.at(i)=='E') e++;
    }
    if((n>0 && w>0 && s>0 && e>0) || (n>0 && w==0 && s>0 && e==0) || (n==0 && w>0 && s==0 && e>0))
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }

    return 0;
}