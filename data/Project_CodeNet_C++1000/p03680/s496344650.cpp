#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 0;
    vector<int> a;

    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    
    int next = 0;
    for(int i=0; i<N; i++)
    {
        count += 1;
        next = a[next] - 1;
        if(next==1)
        {
            cout << count << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}