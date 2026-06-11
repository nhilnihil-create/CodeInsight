#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = s.erase(n-1);
    n = n-1;
    if (n%2==1){
        s = s.erase(n-1);
        n = n-1;
    }
    while (n >= 2){
        string front = s.substr(n/2,n/2);
        string back = s.substr(0,n/2);
        if (front == back){
            cout << n << endl;
            return 0;
        }
        s = s.erase(n-2,2);
        n = n - 2;
    }
    

    return 0;
}