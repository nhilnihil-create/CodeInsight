#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    string s,t;

    cin >> s;

    rep(i,s.size()){
        if(i%2 == 0){
           t += s[i] ;
        }
    }
    
    cout << t << endl;

    return 0;
}