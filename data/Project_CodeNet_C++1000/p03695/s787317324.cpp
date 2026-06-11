#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    int minans = 0;
    int over =0;
    cin >> N;
    set<int> st;

    for (int i=0;i<N;++i)
    {
        int temp;
        cin >> temp;
        if (temp<3200) {
            st.insert(temp/400);
        }
        else {
            ++over;
        }

    }
    cout << max(1, (int)st.size()) << " ";
    cout << st.size()+over << endl;


}
