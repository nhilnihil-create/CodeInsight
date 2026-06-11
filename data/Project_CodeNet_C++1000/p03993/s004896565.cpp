#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> a;
    int in;
    for (int i = 0; i < N; i++)
    {
        cin >> in;
        a.emplace_back(in);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[a[i] - 1] == i + 1)
        {
            ans += 1;
        }
        
    }
    
    cout << ans / 2 << endl;

    return 0;
}