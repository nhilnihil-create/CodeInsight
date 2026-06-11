#include <iostream>
#include <vector>
using namespace std;
int v[250005];
int sol[250005];
int pozitie[250005];
vector <int> c;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a;
        cin >> a;
        v[a] = i;
        pozitie[i] = a;
    }
    int poz = 1;
    for(int i = 1; i <= n * n; i ++)
    {
        if(v[i] != 0)
        {
            int nr = v[i] - 1;
            while(poz < i && nr > 0)
            {
                if(v[poz] == 0)
                {
                    sol[poz] = v[i];
                    nr --;
                }
                poz ++;
            }
            if(nr > 0)
            {
                cout << "No";
                return 0;
            }
            sol[i] = v[i];
        }
    }
    for(int i = 1; i <= n * n; i++)
        if(v[i] > 0)
            for(int j = 1; j + v[i] <= n; j++)
                c.push_back(v[i]);
    poz = 0;
    for(int i = 1; i <= n * n; i ++)
    {
        if(sol[i] == 0)
        {
            if(i < pozitie[c[poz]])
            {
                cout << "No";
                return 0;
            }
            sol[i] = c[poz];
            poz++;
        }
    }
    cout << "Yes" << '\n';
    for(int i = 1; i <= n * n; i ++)
        cout << sol[i] << " ";
    return 0;
}
