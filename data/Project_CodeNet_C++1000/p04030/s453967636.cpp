#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    v<char> ans;
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        switch (S[i])
        {
        case '0':
            ans.push_back('0');
            break;
        case '1':
            ans.push_back('1');
            break;
        case 'B':
            if(ans.size()!=0)
                ans.pop_back();
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;
    
    return 0;
}