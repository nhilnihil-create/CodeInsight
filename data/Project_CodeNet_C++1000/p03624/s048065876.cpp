#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> v(26, 0);
    int len = s.size();
    sort(s.begin(), s.end());
    for(int i = 0; i < len; i++){
        v[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(v[i] == 0){
            char ch = v[i] + 'a' + i;
            cout << ch << endl;
            return 0;
        }
    }
    cout << "None" << endl;

    return 0;
}
