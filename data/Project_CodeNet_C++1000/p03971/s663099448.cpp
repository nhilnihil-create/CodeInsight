#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N, A, B;
    cin >> N >> A >> B;
    char S[N];
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    int through = 0;
    int rank_b = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'a'){
            if(through < (A+B)){
                through++;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if(S[i] == 'b'){
            rank_b++;
            if((through < (A+B)) && (rank_b <= B)){
                through++;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if(S[i] == 'c'){
            cout << "No" << endl;
        }
    }

    return 0;
}