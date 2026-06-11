#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a;
    cin>>n;
    std::deque<long long int> deq;
    for (int i=0;i<3*n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    sort(deq.begin(),deq.end());
    long long int sum=0;
    for (int i=0;i<n;i++) {
        deq.pop_front();
        deq.pop_back();
        long long int tmp=deq.back();
        deq.pop_back();
        sum+=tmp;
    }
    cout<<sum<<endl;
}