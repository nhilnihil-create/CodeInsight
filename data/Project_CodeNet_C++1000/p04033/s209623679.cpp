#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

struct Union_find
{
    vector<int> par;
    vector<int> rank;

    Union_find(int n) : par(n), rank(n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x)
    {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        //根にのみランクが保持されればいい
        if (rank[x] < rank[y])
            par[x] = y;
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        return;
    }
};

int main(){
    int a, b;
    cin >> a >> b;
    if (a<=0 && b>=0)
        cout << "Zero" << endl;
    else if (a>0 && b >0)
        cout << "Positive" << endl;
    else if ((b-a+1) %2 == 0){
        cout << "Positive" << endl;

    }
    else
        cout << "Negative" << endl;
}