#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H>>W;
  vector<vector<string>> data(H+2, vector<string>(W+2,"#"));
  for (int i=1; i<H+1; i++){
        string k;
        cin>>k;
        for (int j=1; j<W+1; j++){
            data.at(i).at(j)=k.at(j-1);
        }
    }
    for (int i =0; i<H+2; i++){
        for(int j =0; j<W+2; j++){ 
          cout<<data.at(i).at(j);     

          if (j==W+1){
          cout<<endl;
          }


        }
      }
      cout<<endl;


}
   
