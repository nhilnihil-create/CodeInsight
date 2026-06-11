#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N,L;
    cin >> N >> L;
    string S[N];
    for(int i = 0 ; i < N ;i++){
        cin >> S[i];
    }
    sort(S,S+N);
    string ans="";
    for(int i = 0 ; i < N ; i++){
        ans += S[i];
    }
    cout << ans << endl;
    return 0;
}