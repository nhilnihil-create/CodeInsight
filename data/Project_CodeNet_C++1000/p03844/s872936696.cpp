#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    string str; getline(cin, str);

    int a = 0, b = 0,  i = 0;
    while(str[i] != ' ') a = a*10 + (str[i] - '0'), i++;

    bool oper = (str[i+1] == '+') ? true : false;

    i += 3;
    while(i<str.size()) b = b*10 + (str[i] - '0'), i++;

    cout<<((oper) ? a + b : a - b)<<endl;
}

int main()
{
    solve();
    Bye;
}
