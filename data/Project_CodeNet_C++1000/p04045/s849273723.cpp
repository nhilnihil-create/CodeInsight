#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<char> v;

bool contains(string a)
{
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < v.size(); j++)
            if(a[i]==v[j]) return true;
    return false;
}

int main()
{
    int a, n;
    char k;
    cin >> a >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }
    for(int i = a; ; i++)
    {
        if(!contains(to_string(i)))
        {
            cout << i;
            return 0;
        }
    }
}

