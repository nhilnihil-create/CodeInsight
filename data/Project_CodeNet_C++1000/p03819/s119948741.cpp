#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

constexpr long long MOD = 1000000007;
constexpr long long INF = (long long)1e18;

#define L second.first
#define R second.second

template<typename T>
class lazy_segment_tree{
        int n;
        T fval;
        vector<T> dat, lazy;

public:

        lazy_segment_tree(){

        }

        lazy_segment_tree(int n_, T val){
                init(n_, val);
        }

        ~lazy_segment_tree(){

        }

        void init(int n_, T val){
                fval = val;

                n = 1;

                while(n < n_) n *= 2;

                dat.resize(2 * n - 1);
                lazy.resize(2 * n - 1, fval);

                for(int i = 0; i < 2 * n - 1; i++) dat[i] = fval;
        }

        void eval(int k, int l, int r){

                if(lazy[k] != fval){
                        dat[k] = dat[k] + lazy[k];

                        if(r - l > 1) {
                                lazy[2*k+1] = lazy[2*k+1] + lazy[k]/2;
                                lazy[2*k+2] = lazy[2*k+2] + lazy[k]/2;
                        }

                        lazy[k] = fval;
                }
        }

        void update(int a, int b, T x, int k = 0, int l = 0, int r = -1){
                if(r < 0) r = n;
                eval(k, l, r);
                if(b <= l || r <= a) {return ;}
                if(a <= l && r <= b){
                        lazy[k] = lazy[k] + (r - l) * x;
                        eval(k, l, r);
                } else {
                        update(a, b, x, 2*k+1, l, (l+r)/2);
                        update(a, b, x, 2*k+2, (l+r)/2, r);
                        dat[k] = dat[2*k+1] + dat[2*k+2];
                }
        }

        T query(int a, int b, int k = 0, int l = 0, int r = -1){
                if(r < 0) r = n;
                eval(k, l, r);
                if(r <= a || b <= l){
                        return fval;
                }
                if(a <= l && r <= b){
                        return dat[k];
                }else {
                        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2 );
                        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                        return vl + vr;
                }
        }
};

signed main(){

 lazy_segment_tree<int> seg;

  int N, M;
  vector<pair<int,pair<int,int>>> in;
  vector<int>  pn;

  cin>>N>>M;

  seg.init(M+10, 0);
  in.resize(N);
  /*
  pn.push_back(1);

  for(int i = 2; i <= M; i++){
    bool flag = false;
    for(int j = 2; j * j <= i; j++){
      if(i%j == 0){
        flag = true;
        break;
      }
    }

    if(flag == false){
      pn.push_back(i);
    }
  }
  */
  for(int i = 0; i < N; i++){
    cin>>in[i].L>>in[i].R;
    in[i].first = in[i].R - in[i].L + 1;
  }

  sort(in.begin(), in.end());



  for(int i = 1, j = 0; i <= M; i++){
    int res = 0;
    // cout<<"i = "<<i<<endl;

    for(; j < N; j++){
      if(in[j].first > i) break;

      seg.update(in[j].L, in[j].R+1, 1);
    }
    /*
    for(int j = 0; j < (int)pn.size(); j++){
      if(pn[j] * i > M) break;

      res += seg.query(pn[j] * i, pn[j] * i + 1);
      //cout<<"pn "<<pn[j] * i<<" "
    }
    */

    for(int j = i; j <= M; j += i){
      res += seg.query(j, j + 1);
    }

    res += N - j;

    cout<<res<<endl;
  }

  return 0;
}
