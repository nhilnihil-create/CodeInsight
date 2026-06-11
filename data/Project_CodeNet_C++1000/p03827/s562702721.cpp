#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s;
    cin >> s;

    long long x = 0;
    long long maxv = 0;

    for(long long i = 0; i < n; i++){
        if(s[i] == 'I'){
            x++;
            maxv = max(maxv, x);
        }
        else if(s[i] == 'D'){
            x--;
            maxv = max(maxv, x);
        }
    }
    cout << maxv << endl;
    return 0;
}