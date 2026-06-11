#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};

using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b;
     if((a+b)%3==0||a%3==0||b%3==0)
        cout<<"Possible";
     else 
        cout<<"Impossible";
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   
 
    solve(); 
   
    return 0;
}
