#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int oorCnt = 0;
    vector<int> colors(8, 0);

    for (int i = 0; i < N; i++)
    {
        int rate = a[i];
        if (rate < 400)
        {
            colors[0]++;
        }
        else if (rate < 800)
        {
            colors[1]++;
        }
        else if (rate < 1200)
        {
            colors[2]++;
        }
        else if (rate < 1600)
        {
            colors[3]++;
        }
        else if (rate < 2000)
        {
            colors[4]++;
        }
        else if (rate < 2400)
        {
            colors[5]++;
        }
        else if (rate < 2800)
        {
            colors[6]++;
        }
        else if (rate < 3200)
        {
            colors[7]++;
        }
        else
        {
            oorCnt++;
        }
    }

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (colors[i] > 0)
            count++;
    }

    int result = 0;

    if(count == 0 & oorCnt > 0){
        cout << 1 << ' ' << oorCnt << endl;
    } else {
        cout << count << ' ' << count + oorCnt << endl;
    }

    return 0;
}
