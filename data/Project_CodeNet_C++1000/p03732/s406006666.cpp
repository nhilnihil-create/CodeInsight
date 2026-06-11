#include <bits/stdc++.h>
using namespace std;
using item= pair<int64_t, int64_t>;
const int Nmax= 200;

pair<double, bool> solveRelaxation(int i_tmp, const bitset<Nmax> *choice, const vector<item> &data, const int &W){
  double ans= 0;
  double W_remain= W;
  for(int i=0; i<i_tmp; i++){
    if(choice->test(i)){
      ans+= data.at(i).first;
      W_remain-= data.at(i).second;
    }
  }

  bool is_RelaxedAns_feasible= true;
  for(int i=i_tmp; i<data.size(); i++){
    double x_i= min(1.0, W_remain/data.at(i).second);

    is_RelaxedAns_feasible= W_remain==(double)data.at(i).second;
    ans+= data.at(i).first* x_i;
    W_remain-= data.at(i).second* x_i;

    if(W_remain <= 0){ break; }
  }

  return make_pair(ans, is_RelaxedAns_feasible);
}

int64_t best_feasible= INT64_MIN;
int64_t solve(int i_tmp, int64_t V_tmp, int64_t W_tmp, bitset<Nmax> *choice, const vector<item> &data, const int &W){
  const int N= data.size();
  if(i_tmp==N){
    best_feasible= max(best_feasible, V_tmp);
    return V_tmp;
  }
  else{
    int64_t RelaxedAns; bool is_RelaxedAns_feasible;
    tie(RelaxedAns, is_RelaxedAns_feasible)= solveRelaxation(i_tmp, choice, data, W);

    if(is_RelaxedAns_feasible){ return RelaxedAns; }
    if(RelaxedAns < best_feasible){ return INT64_MIN; }

    int64_t ans1= INT64_MIN;
    int64_t ans0= INT64_MIN;
    // i_tmp番目のアイテムを選ぶ方の枝を探索
    if(W_tmp+ data.at(i_tmp).second <= W){
      choice->set(i_tmp);
      ans1= solve(i_tmp+1, V_tmp+ data.at(i_tmp).first, W_tmp+ data.at(i_tmp).second, choice, data, W);
      best_feasible= max(best_feasible, ans1);
    }
    // i_tmp番目のアイテムを選ばない方の枝を探索
    choice->reset(i_tmp);
    ans0= solve(i_tmp+1, V_tmp, W_tmp, choice, data, W);
    best_feasible= max(best_feasible, ans0);

    return max(ans1, ans0);
  }
}

int main(){
  int N,W;
  cin >> N >> W;

  vector<item> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i).second >> data.at(i).first;
  }

  auto comp= [](item a, item b){
    return a.first* b.second > b.first* a.second;
  };
  sort(data.begin(), data.end(), comp);

  bitset<Nmax> choice;

  cout << solve(0, 0, 0, &choice, data, W) << endl;
}