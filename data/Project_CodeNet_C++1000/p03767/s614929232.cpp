#include<bits/stdc++.h>
using namespace std;

#define loop(n) for(int i = 0;i < (int)(n);++i)
#define rep(i,n) for(int i = 0;i < (int)(n);++i)
#define all(vec) (vec).begin(),(vec).end()
#define Sort(vec) sort(all(vec))
#define Rev(vec) reverse(all(vec))

namespace Input
{
                
    void input(){return;}
    template<typename First,typename... Rest> void input(First &first,Rest&... rest){
    std::cin >> first;
    input(rest...);
}
    
    void inputVec(){return;}
    template<typename First,typename... Rest> void inputVec(vector<First> &first,Rest&... rest){
        int N = first.size();
        for(int i = 0;i < N;i++){
            cin >> first[i];
        }
        inputVec(rest...);
    }
    
    template<typename First,typename Second> void inputTwoVec(vector<First> &first,vector<Second>& second){
        int N = first.size();
        for(int i = 0;i < N;i++){
            cin >> first[i] >> second[i];
        }
    }
}

void calculate(){
    int N;
    Input::input(N);
    vector<int> a(3 * N);
    Input::inputVec(a);
    Sort(a);
    long long sum = 0;
    for(int i = 3 * N - 2;N <= i; i -= 2)
    {
        sum += a[i];
    }
    cout << sum << '\n';
}

int main(int,char**){
    calculate();    
}


