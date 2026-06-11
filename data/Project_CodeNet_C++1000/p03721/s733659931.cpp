#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()


int main()
{
    ll N, K;
    cin >> N >> K;
    v<pair<int,int>> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i].first >> array[i].second;
    }

    sort(ALL(array));

    for (int i = 0; i < N; i++)
    {
        K-=array[i].second;
        if(K<=0){
            cout << array[i].first << endl;
            return 0;
        }
    }   
    return 0;
}