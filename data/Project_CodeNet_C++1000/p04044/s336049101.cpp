#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int s, l;
    cin >> s >> l;
    vector<string> inp;
    for (int i = 0; i < s; i++)
    {
        string temp;
        cin >> temp;
        inp.push_back(temp);

    }
    sort(inp.begin(), inp.end());
    for (int i = 0; i < s; i++)
    {
        cout << inp[i];

    }
    
}