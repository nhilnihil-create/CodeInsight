#include <iostream>
#include <string>
#define strmax 100000
using namespace std;
std::string s, t;
int pss[strmax+1], pst[strmax+1];
int q;
int m3(int x)
{
    return (x < 0) ? x + 3 : ((x < 3) ? x : x - 3);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t >> q;
    for(int i = 1; i <= s.size(); ++i)
      pss[i] = m3(pss[i - 1] + ((s[i - 1] == 'A') ? 1 : 2));
    for(int i = 1; i <= t.size(); ++i)
      pst[i] = m3(pst[i - 1] + ((t[i - 1] == 'A') ? 1 : 2));
    for(int z = 0; z < q; ++z){
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if(m3(pss[b] - pss[a - 1]) == m3(pst[d] - pst[c - 1]))
        cout << "YES\n";
      else cout << "NO\n";
    }
    return 0;
}
