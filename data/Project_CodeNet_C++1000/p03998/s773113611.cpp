#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    int na=sa.size(),nb=sb.size(),nc=sc.size();

    int a=0,b=0,c=0;
    char t='a';
    while(1){
        if(t=='a'){
            if(a==na){
                cout<<"A"<<endl;
                return 0;
            }
            t=sa[a];
            a++;
        }
        else if(t=='b'){
            if(b==nb){
                cout<<"B"<<endl;
                return 0;
            }
            t=sb[b];
            b++;
        }
        else if(t=='c'){
            if(c==nc){
                cout<<"C"<<endl;
                return 0;
            }
            t=sc[c];
            c++;
        }
    }
}