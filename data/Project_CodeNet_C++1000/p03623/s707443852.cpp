#include <bits/stdc++.h>
using namespace std;

int abs(int a ,int b){
    if(a > b) return a-b;
    else return b-a;
}

int main(){
    int x, a, b;
    cin >> x >> a >> b;
    int ad = abs(x, a);
    int bd = abs(x, b);

    if(ad < bd) cout << "A" << endl;
    else cout << "B" << endl;
}