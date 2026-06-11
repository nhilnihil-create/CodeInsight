#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cnt =0,cntb=1;
    rep(i,0,s.size())
    {
        switch(s[i]){
        case 'c':
            cout << "No" << endl;
            break;
        case 'a':
            if (cnt < a + b){
                cout << "Yes"  << endl;
                cnt +=1;
            }
            else cout << "No" << endl;;
            break;
        case 'b':
            if (cnt < a + b && cntb <= b){
                cout << "Yes"  <<endl;
                cnt += 1;

            }else cout << "No" << endl;
            cntb += 1;
            break;
        }
    }

    return 0;
}
