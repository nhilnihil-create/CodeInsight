#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;
    for(int i=1; i<=b; i++){
        int tmp = (i*a)%b;
        if(tmp == c){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}