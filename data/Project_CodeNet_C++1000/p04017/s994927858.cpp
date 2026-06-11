#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

vector<int> x;
int a[MAX_N],b[MAX_N];
vector<int> G[MAX_N];
int f[MAX_N][2];

int main() {
    int n;
    cin >> n;
    x.push_back(-1);
    srep(i,1,n+1){
        int x_; cin >> x_;
        x.push_back(x_);
    }
    int l,q;
    cin >> l >> q;
    rep(i,q){
        cin >> a[i] >> b[i];
        if(a[i]>b[i])swap(a[i],b[i]);
    }
    
    srep(i,1,n+1){
        if(f[i][0] == 0){
            f[i][0] = i;
            G[i].push_back(i);
            int now = i;
            int day = 1;
            while(true){
                int ma = x[now] + l;
                int ite;
                int l = now+1;
                int r = n;
                while(true){
                    if(x[n]<=ma){
                        ite = n;
                        break;
                    }
                    int mid = (l+r)/2;
                    if(x[mid]<=ma){
                        l = mid;
                    }else{
                        r = mid;
                    }
                    if(l+1==r){
                        ite = l;
                        break;
                    }
                }
                if(ite == n){
                    if(f[n][0]==0){
                        f[n][0] = i;
                        f[n][1] = day;
                        G[i].push_back(n);
                        break;
                    }else{
                        G[i].push_back(n);
                        break;
                    }
                }else{
                    now = ite;
                    if(f[now][0]==0){
                        f[now][0] = i;
                        f[now][1] = day;
                        G[i].push_back(now);
                        day++;
                    }else{
                        G[i].push_back(now);
                        break;
                    }
                }
            }
        }
    }
    
    rep(i,q){
        int day = 0;
        int now[2];
        now[0] = f[a[i]][0];
        now[1] = f[a[i]][1];
        while(true){
            int j = now[0];
            int k = now[1];
            if(G[j][G[j].size()-1] < b[i]){
                day += G[j].size() - 1 - k;
                now[0] = f[G[j][G[j].size()-1]][0];
                now[1] = f[G[j][G[j].size()-1]][1];
            }else{
                break;
            }
        }
        while(true){
            if(G[now[0]].size() - now[1] > 1003){
                if(G[now[0]][now[1]+1000]<b[i]){
                    day += 1000;
                    now[1] += 1000;
                    continue;
                }
            }
            if(G[now[0]].size() - now[1] > 103){
                if(G[now[0]][now[1]+100]<b[i]){
                    day += 100;
                    now[1] += 100;
                    continue;
                }
            }
            if(G[now[0]].size() - now[1] > 13){
                if(G[now[0]][now[1]+10]<b[i]){
                    day += 10;
                    now[1] += 10;
                    continue;
                }
            }
            if(G[now[0]][now[1]+1]<b[i]){
                day++;
                now[1]++;
            }else{
                day++;
                break;
            }
        }
        cout << day << endl;
    }

    return 0;
}
 
 
