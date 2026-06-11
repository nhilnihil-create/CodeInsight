#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

//vector<string> split(string,string);

//template<typename T>
//void swap(T*,T*);

int main()
{
    string s,t,r;
    cin >> s >> t >> r;
    if(s[s.size() - 1] == t[0] && t[t.size() - 1] == r[0])
        Yes(true);
    else
    {
        Yes(false);
    }
    
}