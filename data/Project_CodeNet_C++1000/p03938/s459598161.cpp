#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);

    for (auto i = 0; i < n; i++)
    {
        int pi;
        cin >> pi;
        pi -= 1;
        p[i] = pi;
    }

    vector<long long> num(n);
    vector<long long> num_r(n);
    
    num[0] = 1;
    num_r[0] = 1;


    for (auto i = 1; i < n; i++)
    {
        num[i] = num[i - 1] + 10001;
        num_r[i] = num_r[i - 1] + 10001;
    }

    reverse(num_r.begin(), num_r.end());

    for (auto i = 0; i < n; i++)
    {
        if(i % 2 == 0){
            num[p[i]] += i / 2;
            num_r[p[i]] += i / 2;
        }else{
            num[p[i]] += (i + 1) / 2;
            num_r[p[i]] += i - ((i + 1) / 2);
        }
    }
    for (auto i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    cout << endl;

    for (auto i = 0; i < n; i++)
    {
        cout << num_r[i] << " ";
    }
    cout << endl;
}