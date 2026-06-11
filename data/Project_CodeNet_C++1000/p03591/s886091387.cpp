#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)
#define p(a,b) printf(a,b);
#define o(s) cout<< s << endl;
typedef long long LL;
template <class T>
bool contain(const std::string &s, const T &v)
{
    return s.find(v) != std::string::npos;
}

int main()
{
    string s="",s1;
    cin >> s;
    
    if(s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I'){
        o("Yes");
    }else{
        o("No");
    }
}
