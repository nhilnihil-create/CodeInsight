#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    REP(i, 0, n-1) {
        cin >> v.at(i);
    }

    cout << '\n';
    
    bool flag=true;
    int ind=0;
    set<int> went{};

    while (flag) {

        int tmp;
        tmp = v.at(ind);
        if (went.count(tmp)) {
            cout << "-1";
            return 0;
        }
        went.insert(tmp);

        if (tmp == 2) {
            cout << went.size();
            return 0;
        }
        ind = tmp-1;
    }
}