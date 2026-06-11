#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int freq[122];
int main()
{
    fast_io;
    string w;
    cin >> w;
    int n = w.size();
    for(int i = 0; i < n ;i++)
    {
        freq[w[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < 122; i++)
    {
        if(freq[i] % 2 != 0)
        {
            cnt++;
            break;
        }
    }
    if(cnt > 0)
    {
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
    }
}
