#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,c,k,t;
    cin>>n>>c>>k;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>t;
        deq.emplace_back(t);
    }
    sort(deq.begin(),deq.end());
    const long long INF=1LL<<60;
    long long int limit=INF;
    long long int count=1;
    long long int tmp=c;
    for (int i=0;i<n;i++) {
        if (deq[i]<=limit) {
            limit=min(limit,deq[i]+k);
            tmp--;
        } else {
            count++;
            tmp=c-1;
            limit=deq[i]+k;
        }
        if (tmp==0) {
            if (i!=n-1) {
                count++;
                tmp=c;
                limit=INF;
            }
        }
    }
    cout<<count<<endl;
}