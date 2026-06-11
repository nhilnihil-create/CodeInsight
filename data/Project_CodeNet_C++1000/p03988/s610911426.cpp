#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



int main(){
    int n;cin >> n;
    vector<int> a(n),v(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]]++;
    }
    sort(ALL(a));
    int ma = *max_element(ALL(a));
    int t = (ma + 1) / 2;
    for (int i = 0; i <= ma; i++) {
        if(i==t){
            if(ma%2==0){
                if(v[i]!=1){
                    puts("Impossible");
                    return 0;
                }
            }
            else{
                if(v[i]!=2){
                    puts("Impossible");
                    return 0;
                }
            }
        }
        else if(i < t){
            if(v[i]){
                puts("Impossible");
                return 0;
            }
        }
        else{
            if(v[i]<2){
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");
    return 0;
}
