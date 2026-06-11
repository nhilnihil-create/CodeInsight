#include <bits/stdc++.h>
using namespace std;
int main()
{
    string N;
    cin >> N;
    for(int i=0; i<12; i++)
    {
        cout << N.at(i);
        if(i==3)cout << " ";
    }
    cout << endl;
}