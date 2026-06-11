#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string S;
    cin >> S;

    sort(S.begin(), S.end());
    for(int i=0; i+1<S.size(); i++){
        char a = S[i];
        char b = S[i+1];
        if(a==b){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
    return 0;
}