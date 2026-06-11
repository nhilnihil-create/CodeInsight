#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    string op;

    cin>>a>>op>>b;

    if(op == "+"){
        cout<< a +b<<endl;
    } else {
        cout << a - b << endl;
    }
    return 0;
} 