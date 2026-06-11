# include <iostream>
# include <string>
using namespace std;
int main()
{
    string O, E;
    string ans = "";
    cin >> O >> E;
    for (int i = 0; i < min(O.size(), E.size()); ++i)
    {
        ans = ans + O[i] + E[i];
    }
    if (O.size() > E.size())
        ans = ans + O[O.size() - 1];
    else if (O.size() < E.size())
        ans = ans + E[E.size() - 1];
    cout << ans;
}