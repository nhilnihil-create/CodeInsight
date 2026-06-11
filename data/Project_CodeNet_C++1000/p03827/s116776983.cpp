#include <iostream>
using namespace std;


int main() {
    int n ; cin >> n;
    string s; cin >> s;
    int mx = 0;
    int i = 0;
    for (char c : s){
        if (c == 'I'){
            i++;
        }else{
            i--;
        }
        mx = max(mx , i);
    }
    cout << mx;

}

