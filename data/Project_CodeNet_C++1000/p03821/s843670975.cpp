#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a,b;
    cin>>n;
    std::deque<long long int> A;
    std::deque<long long int> B;
    for (int i=0;i<n;i++) {
        cin>>a;
        A.emplace_back(a);
        cin>>b;
        B.emplace_back(b);
    }
    long long int tmp=0;
    for (int i=n-1;i>=0;i--) {
        if ((A[i]+tmp)%B[i]!=0) {
            tmp+=B[i]-((A[i]+tmp)%B[i]);
        }
    }
    cout<<tmp<<endl;
}