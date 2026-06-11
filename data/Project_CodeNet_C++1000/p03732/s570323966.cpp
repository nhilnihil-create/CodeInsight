#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl 
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl 
#define no cout<<"no"<<endl
#define vec(a,y,x)  vector<vector<char>> a (y,vector<char>(x))
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};

in sum_vec(vector<int> &p,int sup){
  in sum=0;
  rep(i,sup)
    sum+=p.at(i);
  return sum;
}

int main(){
  int n;
  in W;
  cin>>n>>W;
  vector<in> w(n),v(n);
  vector<vector<int>> p(4);
  rep(i,n){
    cin>>w.at(i)>>v.at(i);
    if(i==0) {p.at(0).push_back(v.at(0));continue;}
    rep(j,4){
      if(w.at(i)==w.at(0)+j)
        p.at(j).push_back(v.at(i));
      
    }
  }
  vector<int> size(4);
  rep(j,4){
    size.at(j)=p.at(j).size();
    sort(all(p.at(j)));
    reverse(all(p.at(j)));
  }
  //ここから
  in max_v=0;
  rep(i,size.at(0)+1){
    rep(j,size.at(1)+1){
      rep(k,size.at(2)+1){
        rep(l,size.at(3)+1){
          in sum_w=i*w.at(0)+j*(w.at(0)+1)+k*(w.at(0)+2)+l*(w.at(0)+3);
          if(sum_w>W) continue;
          in sum_v = sum_vec(p.at(0),i)+sum_vec(p.at(1),j)+sum_vec(p.at(2),k)+sum_vec(p.at(3),l);
          max_v = max(max_v,sum_v);
        }
      }
    }
  }
  cout<<max_v<<endl;
}