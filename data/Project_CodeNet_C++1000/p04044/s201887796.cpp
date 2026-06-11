#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,L; 
    cin >> N >> L;

    vector<string> s(N);

    rep(i,N)
        cin >> s[i];
        
    

    sort(s.begin(),s.end());

    rep(i,N)
        cout << s[i];

    cout << endl;



    return 0;
}