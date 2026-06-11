#include<iostream>
#include<set>

using namespace std;

int main()
{
    long long int i, j, a, b, c, n;
    set<int> s;

    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a;

        if(s.count(a))
            s.erase(a);
        else
            s.insert(a);

    }
    cout << s.size();
}
