        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

     signed main(){
int n;
cin>>n;
vector<int> x,y;int a;

    for(int i=0;i<n;i++){
        cin>>a;
        if((n+i)%2)x.push_back(a);
        else y.push_back(a);
    }
    for(int i=0;i<x.size();i++)cout<<x[x.size()-1-i]<<' ';
    for(int i=0;i<y.size();i++)cout<<y[i]<<' ';


     }


 


 






    





      

        
