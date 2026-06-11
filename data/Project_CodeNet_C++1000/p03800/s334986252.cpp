#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int (i)=0;(i) < (N); (i)++)

string animals(string res, int& N, string& S){
    for(int i=1;i<N-1;i++){
        if(res[i] == 'S'){
            if(S[i] == 'o'){
                if(res[i-1] == 'S') res += 'S';
                else res += 'W';
            }
            else {
                if(res[i-1] == 'S') res += 'W';
                else res += 'S';
            }
        }
        else {
            if(S[i] == 'o'){
                if(res[i-1] == 'S') res += 'W';
                else res += 'S';
            }
            else{
                if(res[i-1] == 'S') res += 'S';
                else res += 'W';
            }
        }
    }

    bool ok = true;
    if(res[0] == 'S'){
        if(S[0] == 'o' && res[N-1] != res[1]) ok = false;
        if(S[0] == 'x' && res[N-1] == res[1]) ok = false;
    }
    else {
        if(S[0] == 'o' && res[N-1] == res[1]) ok = false;
        if(S[0] == 'x' && res[N-1] != res[1]) ok = false;
    }
    for(int i=1;i<N;i++){
        if(res[i] == 'S'){
            if(S[i] == 'o' && res[i-1] != res[(i+1)%N]) ok = false;
            if(S[i] == 'x' && res[i-1] == res[(i+1)%N]) ok = false;
        }
        else {
            if(S[i] == 'o' && res[i-1] == res[(i+1)%N]) ok = false;
            if(S[i] == 'x' && res[i-1] != res[(i+1)%N]) ok = false;
        }
    }

    //cout << res << endl;

    if(!ok) return "-1";
    return res;
}

int main(){
    int N;
    string S;
    cin >> N >> S;

    string ans = "-1";

    if(ans == "-1") ans = animals("SS",N,S);
    if(ans == "-1") ans = animals("SW",N,S);
    if(ans == "-1") ans = animals("WS",N,S);
    if(ans == "-1") ans = animals("WW",N,S);

    cout << ans << endl;

}
