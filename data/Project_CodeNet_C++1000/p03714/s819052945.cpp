#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int main() {
    int N;
    cin>>N;
    priority_queue<long, vector<long>, greater<long> > que1;
    priority_queue<long> que2;
    long middle[N];
    long tmp;
    vector<long> ans1, ans2;
    ans1.push_back(0);
    ans2.push_back(0);
    for(int i=0;i<3*N;++i){
        cin>>tmp;
        if(i<N){
            que1.push(tmp);
            ans1[0] += tmp;
        }
        else if(i<2*N){
            middle[i-N] = tmp;
        }
        else{
            que2.push(tmp);
            ans2[0] += tmp;
        }
    }
    for(int i=0;i<N;++i){
        tmp = middle[i];
        if(que1.top() < tmp){
            ans1.push_back(ans1[i] - que1.top() + tmp);
            que1.pop();
            que1.push(tmp);
        }
        else {
            ans1.push_back(ans1[i]);
        }
    }
    for(int i=N-1;i>=0;--i){
        tmp = middle[i];
        if(que2.top() > tmp){
            ans2.push_back(ans2[N-1-i] - que2.top() + tmp);
            que2.pop();
            que2.push(tmp);
        }
        else{
            ans2.push_back(ans2[N-1-i]);
        }
    }
    long ans = ans1[0] - ans2[N];
    for(int i=0;i<=N;++i){
        if(ans < ans1[i] - ans2[N-i]) ans = ans1[i] - ans2[N-i];
    }
    cout<<ans<<endl;
}
