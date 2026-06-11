#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int RLEN=1<<18|1;
inline char nc() {
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
    char ch=nc(); int i=0,f=1;
    while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
    while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
    return i*f;
}

LL n; int tot=0;
deque <int> le,re;
inline void solve(LL n) {
    if(n==1) return;
    solve(n>>1);
    le.push_front(++tot);
    re.push_front(tot);
    if(n&1) {
        le.push_front(++tot);
        re.push_back(tot);
    }
}
int main() {
    cin>>n; solve(n+1);
    cout<<le.size()+re.size()<<endl;
    for(int i=0;i<le.size();++i) cout<<le[i]<<" ";
    for(int i=0;i<re.size();++i) cout<<re[i]<<" ";
}