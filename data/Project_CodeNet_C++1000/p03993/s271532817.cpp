#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    cin>>n;
    std::deque<int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    int count=0;
    for (int i=0;i<n;i++) {
        if (deq[deq[i]-1]==i+1) {
            count++;
        }
    }
    cout<<count/2<<endl;
}