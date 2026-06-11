#include<iostream>
#include<string>
using namespace std;

bool chmax(int& a, int b){
    if (a < b){
        a = b; return true;
    }
    else return false;
}

int main(){
    int N;
    string s;
    cin >> N >> s;
    int score=0, ans=0;
    for (int i=0; i<N; i++){
        if (s[i] == 'I') score++;
        else if (s[i] == 'D') score--;
        chmax(ans, score);
    }
    cout << ans << endl;
    return 0;
}