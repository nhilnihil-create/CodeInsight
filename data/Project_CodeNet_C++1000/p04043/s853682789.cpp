#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> ABC(3);
    int index;
    cin >> ABC[0] >> ABC[1] >> ABC[2];

    auto itr = find(ABC.begin(), ABC.end(), 5);
    if (itr != ABC.end()) {
        index = distance(ABC.begin(), itr);
        ABC.erase(ABC.begin()+index);
    }

    itr = find(ABC.begin(), ABC.end(), 7);
    if (itr != ABC.end()) {
        index = distance(ABC.begin(), itr);
        ABC.erase(ABC.begin() + index);
    }

    itr = find(ABC.begin(), ABC.end(), 5);
    if (itr != ABC.end()) {
        index = distance(ABC.begin(), itr);
        ABC.erase(ABC.begin() + index);
    }

    if (ABC.size() == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
