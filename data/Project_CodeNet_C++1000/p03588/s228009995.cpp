//packages
#include <bits/stdc++.h>//C++14 GCC mode!!!
//alias and namespaces
using namespace std;
//macros
#define REP(i,O,N) for(int i=O;i<N;i++)//うーん、python同様にRange関数でも実装してしまおうかしら…？
#define rep(i,N) for(int i=0;i<N;i++)
#define all(v) v.begin(),v.end()//v.end()-i は[-i]相当
#define debug(x) cerr<< #x <<":"<<x<<endl;
#define v(type) std::vector<type>
#define v2(type)  std::vector<std::vector<type>>
#define v3(type)  std::vector<std::vector<std::vector<type>>>
//functions   



//solution
long sol(int N){
    v2(int) ab;
    
    rep(i,N){
    v(int) temp(2);
    cin >> temp.at(0) >>temp.at(1);
    ab.push_back(temp);
    }
    int m=0;
    int t;
    rep(i,N){
        if (m<ab[i][0]){
            m=ab[i][0];
            t=i;
        }
    }
    
    return (ab[t][0]+ab[t][1]);
}
int main(void){
    //input
    int N;
    cin >>N;
    //output
    //cout<<((ans==1)?"Yes":"No")<<endl;//true to yes
    cout << sol(N)<<endl;//value
    //cout << ans<<endl;//other
    
}
