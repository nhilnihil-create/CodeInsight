#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N = 0 , W = 0 , S = 0 , E = 0;
    string F;
    cin >> F;
    int T = F.size();
    for(int i = 0; i < T; i++){
        if(F.at(i) == 'N'){
            N++;
        }
        if(F.at(i) == 'W'){
            W++;
        }
        if(F.at(i) == 'S'){
            S++;
        }
        if(F.at(i) == 'E'){
            E++;
        }
    }
    if(N > 0 && S > 0 && W > 0 && E > 0){
        cout << "Yes" << endl;
        return 0;
    }
    else if(N == 0 && S == 0 && W > 0 && E > 0){
        cout << "Yes" << endl;
        return 0;
    }
    else if(N > 0 && S > 0 && W == 0 && E == 0){
        cout << "Yes" << endl;
        return 0;
    }
    else if(N == 0 && S == 0 && W == 0 && E == 0){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
