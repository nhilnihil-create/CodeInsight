#include <iostream>
#include <queue>

int main()
{
    int N, x;
    std::cin >> N >> x;

    if(x==1 || x==2*N-1){
        std::cout << "No" << std::endl; return 0;
    }
    printf("Yes\n");
    if(N==2){
        std::cout << "1 2 3" << std::endl; return 0;
    }

    if(x==2*N-2){
        for(int i=1; i<=N-2; i++) printf("%d\n", i);
        printf("%d\n%d\n%d\n%d\n", x-1, x, x+1, x-2);
        for(int i=x-3; i>N-2; i--) printf("%d\n", i);
    }
    else{
        for(int i=1; i<=N-3; i++){
            if(i>=x-1) printf("%d\n", i+4);
            else printf("%d\n", i);
        }
        printf("%d\n%d\n%d\n%d\n", x+2, x-1, x, x+1);
        for(int i=N-2; i<=2*N-5; i++){
            if(i>=x-1) printf("%d\n", i+4);
            else printf("%d\n", i);
        }
    }
}