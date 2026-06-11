#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<int> X(N);
    for(int i=0;i<N;i++){
        cin >> X[i];
        X[i]--;
    }
    vec<int> idx(N);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int i,int j){
        return X[i]<X[j];
    });
    vec<int> ans(N*N,-1);
    int l = 0;
    vec<int> cnt(N);
    bool ok = true;
    for(auto& i:idx){
        ans[X[i]] = i;
        while(cnt[i]<i){
            if(ans[l]==-1){
                ans[l] = i;
                cnt[i]++;
            }
            l++;
        }
        cnt[i]++;
        if(l==N*N) break;
        if(X[i]<l){
            ok = false;
            break;
        }
    }
//    cerr << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
    if(!ok){
        cout << "No\n";
        return 0;
    }
    int r = N*N-1;
    for(int n=N-1;n>=0;n--){
        int i = idx[n];
        while(cnt[i]<N){
            if(ans[r]==-1){
                ans[r] = i;
                cnt[i]++;
            }
            r--;
        }
    }
    vec<int> C(N);
    for(int i=0;i<N*N;i++){
        int a = ans[i];
        C[a]++;
        if(C[a]==a+1){
//            cerr << a << " " << X[a] << "\n";
            ok &= i==X[a];
        }
    }
    if(!ok){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(int i=0;i<N*N;i++) cout << ans[i]+1 << (i!=N*N-1? " ":"\n");
}