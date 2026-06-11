#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);

    for (auto i = 0; i < n; i++)
    {
        long long ai, bi;
        cin >> ai >> bi;
        a[i] = ai;
        b[i] = bi;
    }

    long long index = -1;
    long long point = -1;

    for (auto i = 0; i < n; i++)
    {
        if(index < a[i]){
            index = a[i];
            point = b[i];
        }
    }

    cout << index + point << endl;
}