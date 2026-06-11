#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<int64_t>hari(n);
    for(int i=0;i<n;i++)
         cin >> hari.at(i);
    sort(hari.begin(),hari.end(),greater());
    int64_t ans=hari.at(0);
    for(int i=1;i<n;i++){
         if(ans%hari.at(i)!=0){
            int64_t a=ans;
            while(ans%hari.at(i)!=0)
                ans+=a;
        }
  }
  cout << ans << endl;


    return 0;
}