        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 998244353;


     signed main(){
         cout << std::fixed << std::setprecision(15);
  string a,b;
  cin>>a>>b;
  if(a.size()>b.size()){
       cout<<"GREATER"<<endl;
       return 0;
  }
  if(a.size()<b.size()){
       cout<<"LESS"<<endl;
       return 0;
  }
  if(a>b){
       cout<<"GREATER"<<endl;
       return 0;
  }
   if(a<b){
       cout<<"LESS"<<endl;
       return 0;
  }
  cout<<"EQUAL"<<endl;

 }

 


 






    





      

        
