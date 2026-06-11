#include<cstdio>
int main() {
    int A,B,C;
    scanf("%d%d%d", &A,&B,&C);
    int Ans = 0;
    while(Ans < 99) {
        if(A&1 || B&1 || C&1) break;
        int D=B+C, E=A+C, F=A+B;
        A=D/2, B=E/2, C=F/2;
        ++Ans;
    }
    printf("%d", Ans<99?Ans:-1);
    return 0;
}
//