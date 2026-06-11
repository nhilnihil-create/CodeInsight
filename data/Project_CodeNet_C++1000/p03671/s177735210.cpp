#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a;
    std::deque<int> deq;
    for (int i=0;i<3;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    sort(deq.begin(),deq.end());
    cout<<deq[0]+deq[1]<<endl;
}
