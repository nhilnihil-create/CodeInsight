#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int>v(3);
    cin >> v[0] >> v[1] >> v[2];
    int five = 0, seven = 0;
    for(int i=0; i<3; ++i)
    {
        if(v[i] == 5) five++;
        else if(v[i] == 7) seven++;
    }
    if(five == 2 && seven == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

