#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt4 = 0;
    rep(i, n)
    {
        cin >> a[i];
        if(a[i]%4==0){
            a[i] = 4;
            cnt4++;     
        }else if (a[i]%2==0){
            a[i] = 2;
            cnt2++;
        }else{
            a[i] = 1;
            cnt1++;
        }
    }
    if((cnt2 == 0 && cnt4 != 0 && cnt1 <= cnt4 + 1) || (cnt2 != 0 && cnt4 != 0 && cnt1 <= cnt4) || (cnt2 >= 2 && cnt4 == 0 && cnt1 == 0)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}