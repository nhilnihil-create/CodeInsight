#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    while(N - pow(2, ans) >= 0) ++ans;
    cout << pow(2, ans-1) << endl;
    return 0;
}