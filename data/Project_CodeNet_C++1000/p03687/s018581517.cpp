#include <iostream>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
    int use[26] = {};
    string s;
    cin >> s;
    
    int ans = INT_MAX;
    int cnt;
    int num;

    for (int i = 0; i < 26; i++)
    {
        char ch = i + 'a';
        num = 0;
        cnt = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ch)
            {
                num = max(num, cnt);
                cnt = 0;
            }else
            {
                cnt++;
            }
            
        }
        num = max(num, cnt);
        ans = min(ans, num);
        
    }
    

    cout << ans << endl;

    return 0;
}