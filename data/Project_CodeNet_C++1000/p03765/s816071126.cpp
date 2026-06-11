#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    int n=a.size();
    int m=b.size();
    a="$"+a;
    b="$"+b;
    vector<int> sa(n+1,0);
    for(int i=1;i<=n;i++) sa[i]=sa[i-1]+(a[i]=='A');
    vector<int> sb(m+1,0);
    for(int i=1;i<=m;i++) sb[i]=sb[i-1]+(b[i]=='A');
    int q;
    cin >> q;
    while(q--)
    {
        int c,d,e,f;
        cin >> c >> d >> e >> f;
        int onea=sa[d]-sa[c-1];
        int oneb=(d-c+1)-onea;
        int twoa=sb[f]-sb[e-1];
        int twob=(f-e+1)-twoa;
        if((onea+2*oneb)%3==(twoa+2*twob)%3) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
