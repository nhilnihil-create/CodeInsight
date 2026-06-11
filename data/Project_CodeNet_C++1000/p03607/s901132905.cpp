#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end()); // 降順（大きい順）でソー
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
        {
            if(a[i]==a[i+1]){
                i++;
            }else{
                ans++;
            }
        }
        else
        {
            if (a[i] != a[i - 1]){
                ans++;
            }else if(a[i]==a[i-2]){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}