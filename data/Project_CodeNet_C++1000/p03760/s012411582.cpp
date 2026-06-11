#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e2;

void solve(){
    string a, b; cin>>a>>b;

    char str[MAX];
    for (int i=0, j=0; i<max(a.size(), b.size()); i++, j+=2){
        str[j] = (i<a.size() ? a[i] : ' ');
        str[j+1] = (i<b.size()) ? b[i] : ' ';
    }

    for (int i=0; i<a.size()+b.size(); i++){
        if(str[i] == ' ') continue;
        printf("%c", str[i]);
    } printf("\n");
}

int main(){
    solve();
    Bye;
}