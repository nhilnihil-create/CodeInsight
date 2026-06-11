#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t;
    int n = 0, s = 0, w = 0, e = 0;
    cin >> t;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == 'N') n++;
        else if(t[i] == 'S') s++;
        else if(t[i] == 'W') w++;
        else e++;
    }
    
    bool d = true;

    if((n > 0 && s == 0)||(n == 0 && s > 0)||(w > 0 && e == 0)||(w == 0 && e > 0)) d = false;

    if(d) cout << "Yes" << endl;
    else cout << "No" << endl;

}