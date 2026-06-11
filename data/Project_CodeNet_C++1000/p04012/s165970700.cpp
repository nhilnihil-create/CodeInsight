#include <bits/stdc++.h>
using namespace std;
const int mn = 1000000007;

int main(void)
{
    string w;

    cin >> w;

    map<char, int> cn;
    for(int i = 0; i < w.size(); ++i)
    {
        ++cn[w[i]];
    }    

    bool b = true;

    for(auto iter = begin(cn); iter != end(cn); ++iter)
    {
        if(iter->second % 2 != 0)
        {
            b = false;
        } 
    }

    if(b) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

