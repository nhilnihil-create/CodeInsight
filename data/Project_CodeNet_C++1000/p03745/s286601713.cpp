#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    long long int a;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    int count=0;
    int flag=2;
    for (int i=1;i<n;i++) {
        if (flag==0) {
            if (deq[i-1]>deq[i]) {
                flag=2;
                count++;
            }
        } else if (flag==1) {
            if (deq[i-1]<deq[i]) {
                flag=2;
                count++;
            }
        } else {
            if (deq[i-1]<deq[i]) {
                flag=0;
            } else if (deq[i-1]>deq[i]) {
                flag=1;
            }
        }
    }
    cout<<count+1<<endl;
}