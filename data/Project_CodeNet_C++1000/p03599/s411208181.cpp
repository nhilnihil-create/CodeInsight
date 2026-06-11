#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<int> water;
    for (int i = 1; i * a * 100 <= f; i++)
    {
        for (int j = 0; j * b * 100 + i * a * 100 <= f; j++)
        {
            water.push_back(j * b * 100 + i * a * 100);
        }
    }
    water.push_back(b * 100);
    vector<int> suger;
    for (int i = 0; i * c <= f; i++)
    {
        for (int j = 0; j * d + i * c <= f; j++)
        {
            suger.push_back(j * d + i * c);
        }
    }
    P ans = P(0, a * 100);
    for (auto i : water)
    {
        for(auto j:suger){
            if(i+j>f){
                continue;
            }
            if(i/100*e<j){
                continue;
            }
            if(ans.first*(i+j)<ans.second*j){
                ans = P(j,i+j);
            }
        }
    }
    cout << ans.second << ' ' << ans.first << endl;
    return 0;
}