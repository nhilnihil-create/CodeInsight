#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){

    int n; cin>>n;
    string str; cin>>str;
    int maxi = 0;
    int x = 0;
    for (int i = 0; i<n; i++){
        x = (str[i] == 'I') ? x + 1 : x - 1;
        maxi = max(maxi, x);
    }
    cout<<maxi<<endl;
}

int main(){
    solve();
    Bye;
}