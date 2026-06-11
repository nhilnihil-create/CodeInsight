#include<iostream>
#include<vector>
using namespace std;

class Pair{
    public:
        int prime;
        int counts=0;
        Pair(int prime){
            this->prime = prime;
        }
};
vector<Pair*> primes;

int maybePrimes[1001]={0};
void filterPrimes(){
    maybePrimes[0]=maybePrimes[1]=1;
    for(int i=2; i<=1000; i++){
        for(int j=i+i; j<=1000; j+=i){
            maybePrimes[j]=1;
        }
    }
    for(int i=1; i<=1000; i++){
        if(maybePrimes[i]==0){
            primes.push_back(new Pair(i));
        }
    }
}

void handleDivisors(int n){
    for(int i=0; i<primes.size(); i++){
        while(n%(primes[i]->prime) == 0){
            n/=(primes[i]->prime);
            (primes[i]->counts)++;
        }
        if(n==1){
            break;
        }
    }
}

int main(){
    const int MOD = 1000000007;
    filterPrimes();

    int N;
    cin >> N;

    for(int i=2; i<=N; i++){
        handleDivisors(i);
    }

    long long totalNum = 1;
    for(int i=0; i<primes.size(); i++){
        if((primes[i]->counts)>0){
            totalNum = (totalNum * ((primes[i]->counts)+1))%MOD;
        }
    }

    cout << totalNum << '\n';
}
