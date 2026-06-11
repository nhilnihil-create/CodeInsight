#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
 
 
int main(){
    string S; cin >> S;
    string T = "";
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'T'){
            if(T.size() > 0 && T[T.size()-1] == 'S') T.erase(T.end()-1);
            else T.insert(T.end(), S[i]);
        }
        else T.insert(T.end(), S[i]);
    } 
    cout << T.size() << endl;


}