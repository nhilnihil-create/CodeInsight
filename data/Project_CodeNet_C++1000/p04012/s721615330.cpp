#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

//sort(arr, arr+n, greater<int>())

//for(int i = 0; i < size; i++)
//    cout << a[i] << " ";

map <char, int> s;
map<char, int>::iterator it;

int main()
{
    fast_io;

    string a;
    bool flag = 0;

    cin >> a;

    for(int i = 0; i < a.size(); i++)
    {
        if(s.find(a[i]) == s.end())
        {
            s[a[i]] = 1;
        }

        else
        {
            it = s.find(a[i]);
            it->second++;
        }
    }

    for(it = s.begin(); it != s.end(); it++)
    {
        if(!(it->second & 1)) continue;
        else
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
