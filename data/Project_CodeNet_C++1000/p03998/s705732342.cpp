#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define fi first
#define sec second
#define PB push_back
#define MP make_pair
#define endl '\n'
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)
#define all(v)          v.begin(),v.end()
void fast(){ ios::sync_with_stdio(false); cin.tie(NULL);}
void file()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
}

string a,b,c;
char temp;
int main()
{
    fast();
    

    cin>>a>>b>>c;
    temp = a[0];
    a.erase(0,1);
    while(true){
 
     if(temp == 'a'){
        if(a.size() == 0){
            cout<<"A"<<endl;
            return 0; }
          temp = a[0];
          a.erase(0,1);
     }else if(temp == 'b'){
        if(b.size() == 0){
            cout<<"B"<<endl;
            return 0;
        }
        temp = b[0];
        b.erase(0,1);
     }
     else if(temp == 'c'){
         if(c.size() == 0){
            cout<<"C"<<endl;
            return 0;
         }
         temp = c[0];
         c.erase(0,1);
       }
  }
}
