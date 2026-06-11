#include<iostream>
#include<algorithm>
#include<vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> v = {a,b,c};
    sort(v.begin(),v.end());
    if(v[2] == v[0] + v[1])
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
}
