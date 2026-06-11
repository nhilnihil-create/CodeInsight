#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    ll count4 = 0;
    ll count2 = 0;
    for(ll i = 0; i < N; i++)
    {
        cin >> a[i];
        if(a[i] % 4 == 0 )count4++;
        else
        {
            if(a[i] % 2 == 0)count2++;
        }
        
    }

    if((N / 2) <= count4)
    {
        cout << "Yes" << endl;
    }
    else
    {
        if(N - count4*2 <= count2)cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
        
    }
    return 0;
}