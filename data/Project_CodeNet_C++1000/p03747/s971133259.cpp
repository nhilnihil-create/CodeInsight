typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll n,l,t;
    ll x[100010],w[100010];
    ll after[100010];
    std::cin >> n>>l>>t;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i]>>w[i];
        if(w[i]==1){
            after[i] = (x[i]+t)%l;
            cnt += (x[i]+t)/l;
        }else{
            after[i] = (x[i]-t%l+l)%l;
            if(x[i]-t<0){
                cnt--;
                cnt -= (t-x[i])/l;
                if( (t-x[i])%l==0 ){
                    cnt++;
                } 
            }
        }
        
    }
    sort(after,after+n);
    for(int i=0;i<n;i++){
        cout<<after[(i+cnt%n+n)%n]<<endl;
    }
}
