#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> A(3);
    for(int i=0; i<3; i++) cin >> A.at(i);

    sort(A.begin(), A.end());
    bool flag = true;
    for(auto a : A)
    {
        if(a%2==0) flag = false;
    }
    if(!flag)
    {
        cout << "0\n";
    }
    else
    {
        cout << A[0] * A[1] << '\n';
    }
    

    return 0;
}
