#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    string s,t;
    cin >> N >> s >> t;
    int count = 0;
    for(int i = N; i > 0 ; i -= 1){
        if(s.substr(N-i, i) == t.substr(0,i)){
            count = i;
            break;
        }
    }
    printf("%d\n", 2*N - count);
}