#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int sum = 1;
    if(b!=a){
        sum++;
    }
    if(c!=a&&c!=b){
        sum++;
    }
    cout << sum << endl;
}