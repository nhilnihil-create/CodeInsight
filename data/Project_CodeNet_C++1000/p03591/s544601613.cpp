#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string s;
    cin >> s;

    if(s.size()<4)  puts("No");
    else{
        if (s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I' )
            puts("Yes");
        else    puts("No");
    }

    return 0;
}