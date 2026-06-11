#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
//#define long long ll;


 int main(){

 long long n,x;
  cin>>n;
 vector<int>v;
  long long sum = 0;

 while(n--){

    cin>>x;
    v.push_back(x);
    sum += x;
 }

 sort(v.begin(),v.end());

 if(sum%10 != 0)
  cout<<sum<<endl;
  else {
     int cnt=0;
    while(sum && cnt<v.size()){
         if(v[cnt]%10 != 0)
        sum -= v[cnt];

        if(cnt == n-1) break;

        if(sum %10 != 0)
            break;

         cnt++;
    }

    if(sum %10 != 0)
    cout<<sum<<endl;
    else
        cout<<"0"<<endl;
  }


 return 0;
 }
