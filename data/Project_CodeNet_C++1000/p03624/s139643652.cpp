#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    string S;
    cin >> S;
    vector<char> alpha(26); // 0 = a, 25 = z
    vi counter(26);
    rep(i, 26){
        alpha[i] = 'a' + i;
    }

    rep(i, S.size()){
        rep(j, 26){
            if(S[i] == alpha[j]) counter[j]++;
        }
    }

    rep(i, 26){
        if(counter[i] == 0){
            cout << alpha[i] << endl;;
            return 0;
        }
    }
    cout << "None" << endl;
    
    return 0;
}