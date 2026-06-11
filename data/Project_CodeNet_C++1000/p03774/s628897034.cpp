#include <bits/stdc++.h>
using namespace std;
 


int main() {
 
  int64_t n,m;
  cin>>n>>m;


  vector<pair<int64_t, int64_t> > student_pos(n);
  for(int i=0;i<n;i++){
    cin>>student_pos.at(i).first>>student_pos.at(i).second;
  }
 
  vector<pair<int64_t, int64_t> > checkpoint_pos(m);
  for(int i=0;i<m;i++){
    cin>>checkpoint_pos.at(i).first>>checkpoint_pos.at(i).second;
  }



  for(int i=0;i<n;i++){
    int64_t min_dist=10000000000;
    int64_t index_min_dist;
    for(int j=0;j<m;j++){
      int64_t dist=abs(student_pos.at(i).first-checkpoint_pos.at(j).first)+abs(student_pos.at(i).second-checkpoint_pos.at(j).second);
      if(dist<min_dist){
        min_dist=dist;
        index_min_dist=j+1;
      }
    }
    cout<<index_min_dist<<endl;
  }


	return 0;
}

