#include <bits/stdc++.h>
using namespace std;

int souwa(int n){
    if(n==1){
        return 1;
    }
    return n+souwa(n-1);
}

int main(){
    int N;
    cin >> N;
    cout << souwa(N) << endl;
}
