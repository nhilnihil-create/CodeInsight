#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    queue<char> a,b,c;
    for(auto x:s1) a.push(x);
    for(auto x:s2) b.push(x);
    for(auto x:s3) c.push(x);

    char car = a.front(); a.pop();
    while (1){
        if(car == 'a'){if(a.empty()){ put('A'); break;}car = a.front(); a.pop(); }
        else if(car == 'b'){ if(b.empty()){ put('B'); break; } car = b.front(); b.pop();}
        else if(car == 'c') {if(c.empty()){ put('C');  break; } car = c.front(); c.pop(); }
    }
}