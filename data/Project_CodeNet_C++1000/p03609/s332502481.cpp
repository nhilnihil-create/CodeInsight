#include<bits/stdc++.h>
using namespace std;

int main(){
    int X;
    int t;
    int i,nok;

    cin >> X >>t;
    nok =X;
    for(i=1;((i<=t)&&(X-i>=0));i++){
        nok--;
    }

    cout << nok << endl;
    return 0;
}