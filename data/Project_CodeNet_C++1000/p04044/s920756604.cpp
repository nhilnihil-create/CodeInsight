#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, l;

    cin >> n >> l;

    vector<string> list;

    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        list.push_back(word);
    }

    sort(list.begin(), list.end());
    for (auto const &s : list)
    {
        cout << s;
    }

    cout << endl;
}