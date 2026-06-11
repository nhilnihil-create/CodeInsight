#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec.at(i);
    }
    int count = 0, itr = 0;
    while (vec.at(itr) != 2)
    {
        itr = vec.at(itr) - 1;
        ++count;
        if(count > N){
            cout << -1 << endl;
            return 0;
        }
    }
    count++;
    cout << count << endl;
}