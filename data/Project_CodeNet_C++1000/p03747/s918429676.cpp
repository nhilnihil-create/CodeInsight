#include <bits/stdc++.h>
using namespace std;
#define int long long

 //bool dp[2][4000001];

signed main(){
   int n,l,t,x,w;
   cin >>n>>l>>t;
   vector<int> x1,x2;
   for(int i=0;i<n;i++){
       cin>>x>>w;
       if(w==1)x2.push_back(x);
       else x1.push_back(x);
   }
   int i0=0,i1=0;
   while(i0<x1.size()&&x1[i0]<=t%l-1)i0++;
   while(i1<x2.size()&&x2[x2.size()-1-i1]>=l-t%l)i1++;
   int num=i0-i1+(x1.size()-x2.size())*(t/l);
   while(num<0)num+=n;
   num=num%n;
   priority_queue< int, vector<int>, greater<int> > q;
   int p;
   for(int i=0;i<x1.size();i++){
       p=x1[i]-t;
       while(p<0)p+=l;
       q.push(p);
   }
   for(int i=0;i<x2.size();i++){
     q.push((x2[i]+t)%l);
   }
   int ans[n];
   for(int i=0;i<n;i++){
       ans[(num+i)%n]=q.top();
       q.pop();
   }
   for(int i=0;i<n;i++)cout <<ans[i]<<endl;



    return 0;
}
