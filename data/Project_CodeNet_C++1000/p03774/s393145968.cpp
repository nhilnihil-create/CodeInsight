#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> student;
    vector<pair<int, int>> cp;
    vi answer(n);
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        student.pb(make_pair(a, b));
    }
    while(m--)
    {
        int c, d;
        cin >> c >> d;
        cp.pb(make_pair(c, d));
    }
    for(int i = 0; i < student.size(); i++)
    {
        int mini = inf;
        for(int j = 0; j < cp.size(); j++)
        {
            if(min(mini, abs(student[i].first - cp[j].first)+abs(student[i].second - cp[j].second)) != mini)
            {
                mini = min(mini, abs(student[i].first - cp[j].first)+abs(student[i].second - cp[j].second));
                answer[i] = j+1;
            }
        }
    }

    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}