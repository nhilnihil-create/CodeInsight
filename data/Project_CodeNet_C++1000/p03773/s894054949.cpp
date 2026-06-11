#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a + b > 23){
        cout << (a + b) % 24;
    }else cout << a + b;
    return 0;

}
