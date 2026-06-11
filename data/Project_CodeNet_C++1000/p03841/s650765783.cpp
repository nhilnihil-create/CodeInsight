#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, I, Id;
    cin >> n;
    int K[n+1]={0};
    vector <pair<int,int>> Q;
    deque <int> V, A, B;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        Q.push_back({a,i+1});
    }
    sort(Q.begin(),Q.end());
    for (int i = 0; i < Q.size(); i++)
    {
        a = Q[i].first;
        I = Q[i].second;
        for (int y = 0; y < I-1; y++)
        {
            A.push_back(I);
        }
    }
    Id = 1;
    for (int i = 0; i < n; i++)
    {
        a = Q[i].first;
        I = Q[i].second;
        while (Id < a)
        {
            if (A.size() > 0)
            {
                V.push_back(A.front());
                K[A.front()]++;
                A.pop_front();
            }
            else if (B.size() > 0)
            {
                V.push_back(B.front());
                B.pop_front();
            }
            else
            {
                cout << "No";
                return 0;
            }
            Id++;
        }
        if (Id > a)
        {
            cout << "No";
            return 0;
        }
        if (K[I] < I-1)
        {
            cout << "No";
            return 0;
        }
        V.push_back(I);
        for (int y = I; y < n; y++)
        {
            B.push_back(I);
        }
        Id++;
    }
    while (Id <= n*n)
    {
        Id++;
        V.push_back(B.front());
        B.pop_front();
    }
    cout << "Yes" << "\n";
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    return 0;
}
