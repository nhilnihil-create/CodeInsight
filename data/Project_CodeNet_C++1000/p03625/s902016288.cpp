#include <bits/stdc++.h>
using namespace std;
int main(void){
    std::deque<long long int> deq;
    int n;
    cin>>n;
    long long int a;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    sort(deq.begin(),deq.end(),greater<long long int>());
    std::map<long long int, int> map;
    long long int tmp,max=0,next=0;
    int flag=0;
    for (int j=0;j<n;j++) {
        if (j==0) {
            tmp=deq[j];
            map.emplace(deq[j],1);
        } else {
            if (tmp==deq[j]) {
                map.at(deq[j])++;
                if (j==n-1&&map.at(deq[j])>=2) {
                    if (tmp>max) {
                        next=max;
                        max=tmp;
                    } else if (tmp>next) {
                        next=tmp;
                    }
                }
            } else {
                if (max==0&&map.at(tmp)>=4) {
                    cout<<tmp*tmp<<endl;
                    flag=1;
                    break;
                } else if (map.at(tmp)>=2) {
                    if (tmp>max) {
                        next=max;
                        max=tmp;
                    } else if (tmp>next) {
                        next=tmp;
                    }
                }
                tmp=deq[j];
                map.emplace(deq[j],1);
            }
        }
    }
    if (flag==0) {
        cout<<max*next<<endl;
    }
}