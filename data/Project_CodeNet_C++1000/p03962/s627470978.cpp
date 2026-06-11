#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> abc(3);

    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(), abc.end());
    abc.erase(unique(abc.begin(), abc.end()), abc.end());

    cout << abc.size() << endl;

    return 0;
}