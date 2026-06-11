#include <iostream>
#include <cstdio>
using namespace std;

int n;
string s, t;

int solve(){
    for(int i = 0; i < n; i++){
        if(s.substr(i) == t.substr(0, n-i)){
            return n+i;
        }
    }

    return n+n;
}

int main(){
    
    cin >> n >> s >> t;

    cout << solve() << endl;
    return 0;

}