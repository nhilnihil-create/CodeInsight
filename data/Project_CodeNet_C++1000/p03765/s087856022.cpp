#include<bits/stdc++.h>
using namespace std;
int qs1[100001],qs2[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string A,B;cin >> A >> B;
    for(int i=0;i < A.size();i++) qs1[i+1]=qs1[i]+(A[i] == 'A' ? 1 : 2);
    for(int i=0;i < B.size();i++) qs2[i+1]=qs2[i]+(B[i] == 'A' ? 1 : 2);
    int Q;cin >> Q;
    while(Q--){
        int a,b,c,d;cin >> a >> b >> c >> d;
        int sum1=qs1[b]-qs1[a-1],sum2=qs2[d]-qs2[c-1];
        if(abs(sum1-sum2)%3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
