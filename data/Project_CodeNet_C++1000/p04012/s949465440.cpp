#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int freq[200];

void generateFreq(string s)
{
    int l = s.length();
    for(int i = 0; i < l; i++)
    {
        freq[(int)s[i]]++;
    }
}

bool frequency()
{
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(freq[i] % 2 == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fast_in_out;
    string w;
    cin >> w;
    generateFreq(w);
    if(frequency())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
