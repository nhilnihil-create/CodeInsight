#include <bits/stdc++.h>
using namespace std;

int main()
{
    typedef long long ll;
    int N;
    cin >> N;
    map<string,int> paper;

    for(int i=0; i<N; i++)
    {
        string a;
        cin >> a;
        auto itr = paper.find(a);
        if(itr==paper.end())
        {
            paper[a] = 1;
        }else
        {
            paper.erase(itr);
        }
    }

    cout << paper.size() << endl;
    return 0;
}