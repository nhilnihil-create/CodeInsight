#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int a[2] = {-1, 1};
    int b[2] = {-1, 1};
    int c[2] = {-1, 1};
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 0; j <= 1; j++)
        {
            for(int k = 0; k <= 1; k++)
            {
                vector<int> ani(n+2);
                ani[0] = a[i];
                ani[1] = b[j];
                ani[2] = c[k];
                bool flag = true;

                for(int x = 0; x < n; x++)
                {
                    if(s[x] == 'o')
                    {
                        if(ani[x] * ani[x+1] == -1) 
                        {
                            ani[x+2] = -1;
                        }
                        else ani[x+2] = 1;
                    }
                    else
                    {
                        if(ani[x] * ani[x+1] == 1)
                        {
                            ani[x+2] = -1;
                        }
                        else ani[x+2] = 1;
                    }
                }
                if(ani[1] == ani[n+1] && ani[0] == ani[n])
                {
                    for(int x = 1; x <= n; x++)
                    {
                        if(ani[x] == 1) cout << "S";
                        else cout << "W";
                    }
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}

