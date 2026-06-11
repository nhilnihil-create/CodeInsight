#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    string S;
    ll vec[4] = {0,0,0,0};
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'N') vec[0] = 1;
        if(S[i] == 'S') vec[1] = 1;
        if(S[i] == 'W') vec[2] = 1;
        if(S[i] == 'E') vec[3] = 1;
    }
    if(vec[0] != vec[1] || vec[2] != vec[3]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

}
