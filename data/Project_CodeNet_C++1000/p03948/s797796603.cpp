#include <bits/stdc++.h>
using namespace std;

int N, T;

int main()
{
    cin >> N >> T;
    int min_ = 1000000001;
    int num = 0;
    int prof = 0;
    for (int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        if (a - min_ > prof)
        {
            num = 1;
            prof = a - min_;
        }
        else if (a < min_)
        {
            min_ = a;
        }
        else if (a - min_ == prof)
        {
            num++;
        }
    }
    cout << num << endl;
}
