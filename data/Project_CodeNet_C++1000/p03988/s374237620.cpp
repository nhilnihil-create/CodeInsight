#include "bits/stdc++.h"
using namespace std;
int cnt[101];
int main()
{
    int N;
    cin >> N;
    int maximum = -1;
    for(int i = 0 ; i < N; i++)
    {
        int num;
        cin >> num;
        cnt[num]++;
        maximum = max(maximum, num);
    }
    /*for(int i = 0; i < 10; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;*/
    for(int i = 0; i < (maximum+1)/2; i++)
    {
        if(cnt[i] > 0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(maximum%2 == 0)
    {
        if(cnt[maximum/2] > 1)
        {
            cout << "Impossible" << endl;
        } else {
            for(int i = maximum/2; i < maximum ; i++)
            {
                if(cnt[i] == 0)
                {
                    cout << "Impossible";
                    return 0;
                }
            }
            cout << "Possible" << endl;
        }
    } else
    {
        if(cnt[maximum/2 + 1] > 2)
        {
            cout << "Impossible" << endl;
        } else {
            for(int i = maximum/2+1; i < maximum ; i++)
            {
                if(cnt[i] == 0)
                {
                    cout << "Impossible";
                    return 0;
                }
            }
            cout << "Possible" << endl;
        }
    }
}
