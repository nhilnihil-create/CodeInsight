#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int main(void){
    int n,a[300000],b=1;
    P p[500];
    queue<int> q;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p[i]=P(x, i+1);
    }
    fill(a, a+n*n+2, 0);
    sort(p, p+n);
    for(int i=0;i<n;i++){
        int x=p[i].first, y=p[i].second;
        for(int j=1;j<y;j++){
            while(b<x&&a[b]>0)b++;
            if(b==x){
                cout<<"No"<<endl;
                return 0;
            }
            a[b]=y;
        }
        a[x]=y;
    }
    int t=0;
    for(int i=1;i<=n*n;i++){
        if(t<n&&i==p[t].first){
            int s=p[t].second;
            for(int j=s;j<n;j++){
                q.push(s);
            }
            t++;
        }
        if(a[i]==0){
            if(q.empty()){
                cout<<"No"<<endl;
                return 0;
            }
            a[i]=q.front();
            q.pop();
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n*n;i++){
        cout<<a[i];
        if(i<n*n)cout<<" ";
    }
    cout<<endl;
}
