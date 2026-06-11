#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;

int n, m;

int a, b;

int ua, ub;

vector <vector <int> > graf;
vector <int> vi;

list <int> rj;

bool bio[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    graf.insert(graf.begin(), n, vi);
    REP(i, 0, m)
    {
        scanf("%d%d", &ua, &ub);
        ua--; ub--;
        graf[ua].push_back(ub);
        graf[ub].push_back(ua);
    }
    a = 0;
    bio[a] = 1;
    b = graf[a][0];
    bio[b] = 1;
    rj.push_back(a);
    rj.push_front(b);
    while(1)
    {
        bool z = 0;
        REP(i, 0, (int) graf[a].size())
        {
            if(!bio[graf[a][i]])
            {
                z = 1;
                a = graf[a][i];
                bio[a] = 1;
                rj.push_back(a);
                break;
            }
        }
        if(!z) break;
    }
    while(1)
    {
        bool z = 0;
        REP(i, 0, (int) graf[b].size())
        {
            if(!bio[graf[b][i]])
            {
                z = 1;
                b = graf[b][i];
                bio[b] = 1;
                rj.push_front(b);
                break;
            }
        }
        if(!z) break;
    }
    printf("%d\n", (int) rj.size());
    for(list <int>::iterator it = rj.begin(); it != rj.end(); it++)
    {
        printf("%d ", (*it) + 1);
    }
    return 0;
}
