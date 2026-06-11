#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    int N; cin >> N;
    string S; cin >> S;
    vector<char> t(N+1);

    vector<string> ani = {"SS", "SW", "WS", "WW"};
    rep(i, 0, 4){
        t[0] = ani[i][0];
        t[1] = ani[i][1];
        rep(j, 1, N){
            // もしj番目の動物が羊だったら
            if(t[j] == 'S'){
                if(S[j] == 'o'){
                    if(t[j-1] == 'S') t[j+1] = 'S';
                    else t[j+1] = 'W';
                }else{
                    if(t[j-1] == 'S') t[j+1] = 'W';
                    else t[j+1] = 'S';
                }
            }else{
                if(S[j] == 'o'){
                    if(t[j-1] == 'S') t[j+1] = 'W';
                    else t[j+1] = 'S';
                }else{
                    if(t[j-1] == 'S') t[j+1] = 'S';
                    else t[j+1] = 'W';
                }
            }
        }
        if(t[0] == 'S'){
            if(S[0] == 'o'){
                if(t[1] != t[N - 1]) continue;
            }else{
                if(t[1] == t[N-1]) continue;
            }
        }else{
            if(S[0] == 'o'){
                if(t[1] == t[N-1]) continue;
            }else{
                if(t[1] != t[N-1]) continue;
            }
        }
        if(t[N] == t[0]){
            rep(i, 0, N){
                cout << t[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
}