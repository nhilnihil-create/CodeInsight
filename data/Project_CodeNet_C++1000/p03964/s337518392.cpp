#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll n;
    std::cin >> n;
    ll vote, t_vote, a_vote;
    std::cin >> t_vote >> a_vote;
    vote = t_vote + a_vote;
    for(int i = 1; i < n; i++){
        ll t, a;
        std::cin >> t >> a;
        /*
        if(vote % (t + a) != 0){
            vote = (vote / (t + a) + 1) * (t + a); 
        }
        */
        ll k_min = std::max(t_vote / t, a_vote / a);
        // vote >= k_min * (t + a)である必要がある
        vote = k_min * (t + a);        
        for(; ; vote += t + a){
            ll k = vote / (t + a);
            ll t_target = k * t;
            ll a_target = k * a;
            if(t_target < t_vote) continue;
            if(a_target < a_vote) continue;
            t_vote = t_target;
            a_vote = a_target;
            break;
        }
    }

    std::cout << vote << std::endl;

    return 0;
}
