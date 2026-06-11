#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N , A , B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    int a = 0 , b = 0;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'a' && a + b < A + B){
            cout << "Yes" << endl;
            a++;
        }
        else if(S.at(i) == 'b' && a + b < A + B && b < B){
            cout << "Yes" << endl;
            b++;
        }
        else{
            cout << "No" << endl;
        }
    }
}
