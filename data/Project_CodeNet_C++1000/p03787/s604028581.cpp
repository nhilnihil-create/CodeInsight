#include<bits/stdc++.h>
using namespace std;

#define int long long

class union_find
{
        int  _setnum;
        vector<int> par, nume;
public:
        union_find(){
        }

        union_find(int x){
                par.resize(x);
                nume.resize(x);
                init();
        }

        ~union_find(){
                //

        }

        void clear(){
                _setnum = 0;
                par.clear();
                nume.clear();
        }

        void init(){
                _setnum = par.size();
                for(int i = 0; i < par.size(); i++){
                        par[i] = i;
                        nume[i] = 1;
                }
        }

        void resize(int x){

                par.resize(x);
                nume.resize(x);
                init();
        }

        int find(int x){
                return par[x] == x ? x : par[x] = find(par[x]);
        }

        void unite(int x, int y){
                x = find(x);
                y = find(y);

                if(x == y)return;

                _setnum--;

                if(nume[x] > nume[y]) std::swap(x,y);

                par[x] = y;
                nume[y] += nume[x];
        }

        bool same(int x, int y){
                return find(x) == find(y);
        }

        int numel(int x){
                return nume[find(x)];
        }

        int size(){
                return par.size();
        }

        int setnum(){
                return _setnum;
        }
};


signed main(){

  int N, M;
  int a = 0, b = 0, c = 0;
  vector<pair<int,int>> in;
  vector<int> used, con;
  union_find uf, uf2;

  cin>>N>>M;

  in.resize(M);

  uf.resize(N);

  uf2.resize(N*2);

  used.resize(N*2);

  con.resize(N);

  for(int i = 0; i < M; i++){
    cin>>in[i].first>>in[i].second;

    in[i].first--;

    in[i].second--;
  }

  for(int i = 0; i < M; i++){
    uf.unite(in[i].first, in[i].second);

    uf2.unite(N + in[i].first, in[i].second );
    uf2.unite(N + in[i].second, in[i].first );
  }

  for(int i = 0; i < N; i++){
    if(used[uf2.find(i+N)] == false) {
      used[uf2.find(i+N)] = true;
      con[uf.find(i)]++;
    }

    if(used[uf2.find(i)] == false) {
      used[uf2.find(i)] = true;
      con[uf.find(i)]++;
    }

  }

  used.clear();
  used.resize(N, false);

  for(int i = 0; i < N; i++){
    if(used[uf.find(i)]) continue;
    used[uf.find(i)] = true;
    //cout<<"i = "<<i<<" con "<<" "<<con[uf.find(i)]<<" "<<uf.find(i)<<endl;

    //if(con[uf.find(i)] == 0){
    if(uf.numel(i) == 1) {
      a++;
    } else if(con[uf.find(i)] == 1){
      c++;
    } else {
      b++;
    }
  }

  int ans = 0;

  // cout<<a<<" "<<b<<" "<<c<<endl;

  ans = b * b + (b + c) * (b + c) + a * a + (N-a) * a * 2;
  ///  cout<<b * b + (b + c) * (b + c)<<endl;
  // cout<<a * a <<" "<< (N - a) * a * 2<<endl;

  cout<<ans<<endl;

  // cout<<uf.setnum()<<endl;

  return 0;

  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      cout<<"( "<<in[i].first<<", "<<in[j].first<<") -> "<<"( "<<in[i].second<<", "<<in[j].second<<")"<<endl;
      cout<<"( "<<in[i].first<<", "<<in[j].second<<") -> "<<"( "<<in[i].second<<", "<<in[j].first<<")"<<endl;

      uf.unite(in[i].first * N + in[j].first, in[i].second * N + in[j].second );
      uf.unite(in[i].first * N + in[j].second, in[i].second * N + in[j].first );
    }
    cout<<endl;
  }

  cout<<uf.setnum()<<endl;

  return 0;
}
