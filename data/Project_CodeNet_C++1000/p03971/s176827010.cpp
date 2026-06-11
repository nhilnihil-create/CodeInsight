// 15:38-15:43
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    char S[N];
    rep(i, N) cin >> S[i];
    int passa = 0;
    int passb = 0;

    rep(i, N){
        if (S[i] == 'c'){
            cout << "No" << endl;
        }else if (S[i] == 'a'){
            if (passa + passb < A + B){
                cout << "Yes" << endl;
                passa++;
            }else{
                cout << "No" << endl;
            }
        }else if (S[i] == 'b'){
            if ( (passa + passb < A + B) && (passb < B) ){
                cout << "Yes" << endl;
                passb++;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}