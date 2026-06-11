#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n ; cin>>n;
    vector<int>v(n);
    double s = 0.0;
    for(int& i : v){
        cin>>i;
        s += i;
    }
    int mid = round(s / (1.0 * n));
    int ans = 0;
    for(int& i : v){
        ans += (i - mid) * (i - mid);
    }
    cout<<ans<<"\n";
    
}
