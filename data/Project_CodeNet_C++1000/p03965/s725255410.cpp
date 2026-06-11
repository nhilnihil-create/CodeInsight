#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    ll count = 0;
    for(char c : s){
        if(c == 'g'){
            count++;
        }else{
            count--;
        }
    }
    cout << count / 2 << endl;
    return 0;
}
