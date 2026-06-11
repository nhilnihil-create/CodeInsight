#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(3*n);
    for(int i=0; i<3*n; i++)
    cin >> a.at(i);

    sort(a.rbegin(),a.rend());

    long long sum=0;
    for(int i=0; i<n; i++){
        sum += a.at(i*2+1);
    }
    cout << sum << endl;



}