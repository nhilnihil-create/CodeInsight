/*
      author : nishi5451
      created: 11.08.2020 01:00:46
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n; 
    cin >> n;
    if(n/100 == n%10) cout <<" Yes" << endl;
    else cout << "No" << endl;
    return 0;
}