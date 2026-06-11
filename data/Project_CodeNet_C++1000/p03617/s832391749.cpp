#include <bits/stdc++.h>
using namespace std;
std::vector<tuple<long long int,long long int,long long int>> v;

// x*8,4,2,1 : x : litres
int main() { 
     long long int arr[] = {8,4,2,1};
     long long int litres[] = {1,2,4,8};
     for(long long int i=0;i<4;i+=1){
          long long int x;
          cin >> x;
          v.push_back(make_tuple(arr[i]*x,x,litres[i]));
     }
     sort(v.begin(),v.end());
     long long int L;
     cin >> L;
     L*=4;
     long long int i=0;
     long long int ans = 0;
     while(L!=0 && i<4){
          // for(long long int i=0;i<4;i+=1){
               if(L-get<2>(v[i])>=0){
                    L-=get<2>(v[i]);
                    ans+=get<1>(v[i]);
                    // cout << get<1>(v[i]) << endl;
               }
               else{
                    i+=1;
               }
          // }
     }
     cout << ans;
}
