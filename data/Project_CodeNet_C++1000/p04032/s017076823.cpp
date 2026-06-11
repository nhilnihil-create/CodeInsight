#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            cout << i+1 << " " << i+2;
            return 0;
        }
    }

    for(int i=0;i<s.size()-2;i++){
        if(s[i]==s[i+2]){
            cout << i+1 << " " << i+3;
            return 0;
        }
    }

    cout << "-1 -1";

    return 0;
}
