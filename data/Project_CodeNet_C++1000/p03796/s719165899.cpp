#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long a = 1;
    for(int i = 0; i < N; i++){
        a = a * (i + 1) % 1000000007;
    }
    cout << a << endl;
}
