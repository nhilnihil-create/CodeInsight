#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
long double eps = 1e-9;
long double pi = acos(-1);



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq,q;
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
        q.push({a[i],i+1});
    }
    int ans[n*n]={};
    for(int i=0;i<n;i++){
        ans[a[i]] = i+1;
    }
    int now = 0;
    while(pq.size()){
        array<int,2> r = pq.top();
        pq.pop();
        int cnt = 0;
        while(now<n*n && cnt<r[1]){
            if(ans[now]){
                now++;
                continue;
            }
            ans[now] = r[1]+1;
            cnt++;
            now++;
        }
        if(r[0] < now){
            cout << "No\n";
            return 0;
        }
    }
    now = 0;
    while(q.size()){
        array<int,2> r = q.top();
        q.pop();
        int cnt = 0;
        // r[1] を、n-r[1]こ
        while(cnt<n-r[1]){
            if(ans[now]){
                now++;
                continue;
            }
            if(now <= r[0]){
                cout << "No\n";
                return 0;
            }
            ans[now] = r[1];
            cnt++;
            now++;
        }
    }
    cout << "Yes\n";
    for(int i=0;i<n*n;i++){
        cout << ans[i]<<" ";
    }
    cout << endl;


}