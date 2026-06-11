#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int res;
    cin >> N;

    for(double i=0.0; i<=7.0;i++){
        if(N>=pow(2.0, i))
            res = pow(2.0, i);
    }
    cout << res << endl;
}