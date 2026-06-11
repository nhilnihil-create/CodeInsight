        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 1000001;
const int MOD =1000000007;
const int INV2 = (MOD+1)/2;



     signed main(){
 int n;
 cin>>n;n++;
 vector<int> x,y,z;
 int k=0;while((1ll<<k)<=n)k++;
 k--;
 int b=100;
 for(int i=0;i<k;i++){
   if(n&(1ll<<i)){
     y.push_back(b);
     z.push_back(b);
     b--;
   }
   x.push_back(i+1);
   z.push_back(i+1);
 }
 cout<<x.size()+y.size()+z.size()<<endl;
 for(int i=0;i<x.size();i++)cout<<x[i]<<' ';
 for(int i=y.size()-1;i>=0;i--)cout<<y[i]<<' ';
 for(int i=0;i<z.size();i++)cout<<z[i]<<' ';
 cout<<endl;



}


        
