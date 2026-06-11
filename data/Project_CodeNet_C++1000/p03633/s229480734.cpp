#include <iostream>
const int64_t MAX = 1000000000000000000;
int64_t gcd(int64_t a, int64_t b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int64_t lcm(int64_t a, int64_t b)
{
    return (a / gcd(a, b)) * b;

}

int64_t lcm_array(int64_t *data_array, int N)
{
    if (N==1){
        return data_array[0];
    }
    else{
    int64_t tmp = data_array[0];
    for (int i = 1; i < N; i++)
    {
        
        tmp = lcm(tmp, data_array[i]);
    }
    return tmp;
    }
}



int main()
{   
    int N;
    std::cin >> N;
    int64_t T[N];
    int64_t ans;
    for (int i = 0; i < N; i++)
    {
        std::cin >> T[i];
        
        

        }
    
    for (int i = 0; i < N; i++)
    {
        if (T[i] == MAX)
        {
            ans = MAX;
            std::cout << ans << std::endl;
            
        return 0;
        }
        
    }
    
    ans = lcm_array(T, N);

    std::cout << ans << std::endl;
    return 0;
}