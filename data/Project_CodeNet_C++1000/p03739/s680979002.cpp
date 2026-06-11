#include <iostream>
#include <vector>

long body(std::vector<long>& a, long base){
    long ans  = 0;
    
    std::vector<long> s(a.size());
    s.at(0) = a.at(0);
    for(unsigned long i = 1; i < a.size(); i++){
        s.at(i) = s.at(i-1) + a.at(i);
    }

    long diff = 0;
    long prev = base;
    for(unsigned long i = 0; i < s.size(); i++){
        s.at(i) += diff; // update
        long n = 0;
        if(prev > 0 && s.at(i) >= 0){
            n = s.at(i) + 1;
            ans += n;
            diff -= n;
        }else if(prev < 0 && s.at(i) <= 0){
            n = - s.at(i) + 1;
            ans += n;
            diff += n;
        }
        prev = - prev;
    }
    return ans;
}

int main(int argc, char **argv)
{
    long n;
    std::cin >> n;

    std::vector<long> a(n);
    for(long i = 0; i < n; i++){
        std::cin >> a.at(i);
    }

    long ans_a, ans_b;
    
    ans_a = body(a, -1);
    ans_b = body(a, 1);
    
    long ans = std::min(ans_a, ans_b);

    std::cout << ans << std::endl;
    
}
