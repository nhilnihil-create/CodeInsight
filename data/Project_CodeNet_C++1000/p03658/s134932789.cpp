#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,sum=0;
    cin >> n >> k;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
    {
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end(),greater<int>());
    for(int i=0;i<k;i++)
    {
        sum += ar[i];
    }
    cout << sum << endl;
    return 0;
}
