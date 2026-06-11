#include <iostream>
#include <vector>

int main()
{
    int N;
    scanf("%d", &N);
    std::vector<int> p(N);
    for(int i=0; i<N; i++){
        scanf(" %d", &p[i]); p[i]--;
    }

    int count = 0;
    for(int i=0; i<N-1; i++){
        if(p[i] == i){
            p[i+1] = i; count++;
        }
    }
    if(p[N-1] == N-1) count++;

    std::cout << count << std::endl;
}