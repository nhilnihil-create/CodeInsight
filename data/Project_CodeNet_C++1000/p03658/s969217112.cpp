#include<bits/stdc++.h>

#define loop(n) for(int i = 0;i < (int)(n);++i)
#define rep(i,n) for(int i = 0;i < (int)(n);++i)
#define all(vec) (vec).begin(),(vec).end()
#define sort(vec) std::sort(all(vec))
#define rev(vec) std::reverse(all(vec))
#define cout std::cout

template<typename T>
using vec = std::vector<T>;

void input(){return;}
template<typename First,typename... Rest> void input(First &first,Rest&... rest){
    std::cin >> first;
    input(rest...);
}

void inputVec(){return;}
template<typename First,typename... Rest> void inputVec(vec<First> &first,Rest&... rest){
    int N = first.size();
    for(int i = 0;i < N;i++){
        std::cin >> first[i];
    }
    inputVec(rest...);
}

template<typename First,typename Second> void inputTwoVec(vec<First> &first,vec<Second>& second){
    int N = first.size();
    for(int i = 0;i < N;i++){
        std::cin >> first[i] >> second[i];
    }
}

void calculate(){
    int n,k;
    input(n,k);
    vec<int> l(n);
    inputVec(l);
    sort(l);
    rev(l);
    int res = 0;
    rep(i,k){
        res += l[i];
    }
    cout << res << '\n';
}

int main(int,char**){
    calculate();    
}


