#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    bitset<26> state(0);
    bitset<26> state_true; state_true.set();

    vector<int> p{(int)A.size()};

    for (int i=A.size()-1; i>=0; i--)
    {
        state.set(A[i] - 'a');
        if (state == state_true)
        {
            state.reset();
            p.push_back(i);
        }
    }

    int start = 0;
    while(!p.empty())
    {
        state.reset();
        for (int i=start; i<p.back(); i++) state.set(A[i] - 'a');

        for (int i=0; i<26; i++)
        {
            if (!state[i])
            {
                cout << (char)('a'+i);
                for (int j=p.back(); j<A.size(); j++)
                {
                    if ((char)('a'+i) == A[j])
                    {
                        start = j + 1;
                        break;
                    }
                }
                break;
            }
        }
        p.pop_back();
    }
    return 0;
}