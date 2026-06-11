#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
   int N,W; cin>>N>>W;
   int wmin,v; cin>>wmin>>v;
   vector<vector<int>> wv(N,vector<int>(4));
   wv[0].push_back(v);
   for(int i=0;i<N-1;i++){
       int w; cin>>w>>v;
       wv[w-wmin].push_back(v);
   }
   for(int i=0;i<4;i++){
       sort(wv[i].begin(),wv[i].end());
       reverse(wv[i].begin(),wv[i].end());
   }
   for(int i=0;i<4;i++){
       for(int j=1;j<wv[i].size();j++){
           wv[i][j]+=wv[i][j-1];
       }
   }
   int ans=0;
   for(int end0=0;end0<=wv[0].size();end0++){
       for(int end1=0;end1<=wv[1].size();end1++){
           for(int end2=0;end2<=wv[2].size();end2++){
               for(int end3=0;end3<=wv[3].size();end3++){
                   if(wmin*end0+(wmin+1)*end1+(wmin+2)*end2+(wmin+3)*end3<=W){
                       int tmp=0;
                       if(end0!=0)tmp+=wv[0][end0-1];
                       if(end1!=0)tmp+=wv[1][end1-1];
                       if(end2!=0)tmp+=wv[2][end2-1];
                       if(end3!=0)tmp+=wv[3][end3-1];
                       ans=max(ans,tmp);
                   }
               }
           }
       }
   }
   cout<<ans<<endl;
}