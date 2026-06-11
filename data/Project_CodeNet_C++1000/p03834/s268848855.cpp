#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    string str; cin>>str;
    for (int i=0; i<str.size(); i++)
        printf("%c", str[i] == ',' ? ' ': str[i]);
    printf("\n");
}

int main()
{
    solve();
    Bye;
}