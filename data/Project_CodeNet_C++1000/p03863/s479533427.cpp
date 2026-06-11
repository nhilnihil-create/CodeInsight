#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    int l = s.size();
    char first = s[0];
    char last = s[l-1];

    if(first == last){
        cout << (l % 2 == 0 ? "First" : "Second") << endl;
    }
    else{
        if(l % 2 != 0)cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}

