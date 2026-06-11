#include<bits/stdc++.h>


void input(); template<typename First,typename... Rest> void input(First&,Rest&...);
void inputVector(); template<typename First,typename... Rest>  void inputVector(std::vector<First>&,Rest&...);
#define loop(n) for(int i = 0;i < (int)(n);++i)
#define rep(i,n) for(int i = 0;i < (int)(n);++i)
#define all(vec) (vec).begin(),(vec).end()
#define sort(vec) std::sort(all(vec))
#define rev(vec) std::reverse(all(vec))

void calculate(){

}

int main(int,char**){
    std::string t;
    input(t);
    for(int i = 0;i < (int)t.size();i += 2){
        std::cout << t[i];
    }
    std::cout << '\n';
}


void input(){return;}
template<typename First,typename... Rest>
void input(First &first,Rest&... rest){
    std::cin >> first;
    input(rest...);
}

void inputVector(){return;}
template<typename First,typename... Rest> 
void inputVector(std::vector<First> &first,Rest&... rest){
    int N = first.size();
    for(int i = 0;i < N;i++){
        std::cin >> first[i];
    }
    inputVector(rest...);
}