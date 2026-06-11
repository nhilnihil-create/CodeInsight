#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();
    int edgeCnt = 0;
    for (int i = 1; i < n; i++)
    {
        if(s[i] != s[i-1]){
            edgeCnt++;
        }
    }
    
    cout << edgeCnt << endl;

    return 0;
}
