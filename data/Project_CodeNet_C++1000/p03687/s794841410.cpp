        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
    const int MAX =200002;
const int MOD =1000000007;

     signed main(){
int ans=MOD;string s,x;
cin>>s;
for(char i0='a';i0<='z';i0++){
    x=s;
    int n=x.size();
    for(int i=1;i<=s.size();i++){
        bool k=true;
        if(x[0]!=i0)k=false;
        for(int j=0;j<s.size()-i;j++){
            if(x[j+1]==i0)x[j]=i0;
            else k=false;
        }
        if(k){ans=min(ans,i-1);break;}
    }
}
cout<<ans<<endl;


     }


 


 






    





      

        
