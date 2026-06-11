#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    string str; cin>>str;
    int i = 0, j = str.size() - 1;
    while(str[i]!='A') i++;
    while(str[j]!='Z') j--;
    cout<<(j-i)+1<<endl;
}

int main(){
    solve();
    Bye;
}