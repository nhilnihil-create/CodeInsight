#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a;
    int ary[100002] = {};
    int mx = 0;

    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        
        ary[temp-1] += 1;
        ary[temp] += 1;
        ary[temp+1] += 1;
    }

    for(int i=0; i<100002; i++)
    {
        // cout <<  i-1 << ": " << ary[i] << endl;
        if(mx < ary[i]) mx = ary[i];
    }
    cout << mx << endl;
    return 0;
}