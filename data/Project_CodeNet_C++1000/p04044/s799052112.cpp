#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>> n >> m;

    string input;

    vector<string>vec;

    for(int i = 1; i <= n; i++)
    {
        cin>> input;
        vec.push_back(input);
    }

    sort(vec.begin(),vec.end());

    for(int i = 0; i < vec.size(); i++)
    {
        cout<< vec[i];
    }

    return 0;
}
