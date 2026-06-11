#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<ll> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            k.emplace_back(i + 1);
        }
    }
  
    for (int i = 0; i < h; i++)
    {
        if(i % 2 == 0){
            for(int j = 0; j < w; j++)
            cout << k[i * w + j] << " ";
        }
        else{
            for(int j = w - 1; 0 <= j; j--){
                cout << k[i * w + j] << " ";
            }
        }
        cout << endl;
    }
}