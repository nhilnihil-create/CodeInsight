#include <bits/stdc++.h>
using namespace std;

int main(){

    string N,ans;
    cin >> N;
    int i = 0;

    while(i < N.size()){
      ans += N[i];
      i += 2;
    }
    
    cout << ans << endl;
}