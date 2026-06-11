#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vec;
bool turno = 0;
ll gcd(ll a, ll b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}


ll gcdTodos(){
    ll act = gcd(vec[0], vec[1]);
    for(long i = 2; i < vec.size(); i++){
        act = gcd(act, vec[i]);
    }
    return act;
}

void solve(){
    //cout << turno <<'\n';
    bool todosUn = true;
    for(long i = 0; i <vec.size() ; i++){
        if(vec[i] != 1){
            todosUn = false;
            break;
        }
    }
    if(todosUn){
        if(turno){
                turno = 0;
            }else {
                turno = 1;
            }

        return;
    }
    /*for(long i = 0; i <vec.size() ; i++){
        cout << vec[i]<<" ";
    }*/
    //cout<<'\n';
    long numPar = 0;
    long numImpar = 0;
    for(long i = 0; i < vec.size(); i++){
        if(vec[i] % 2 == 0){
                numPar++;
        }else{
            numImpar++;
        }
    }
    if(numPar % 2 == 1){
        //cout << "Numero impar de pares\n";
        return ;

    }else if((numPar % 2 == 0) && (numImpar >= 2)){
        //cout<<"Par numero de pares y 2 o mas impares\n";
        if(turno){
            turno = 0;
        }else turno = 1;
        return;
    }else{
        bool cambio = false;
        //cout << "Simular\n";
        for(long i = 0; i < vec.size(); i++){
            if(vec[i] % 2 == 1 && (vec[i]!= 1)){
                cambio = true;
                vec[i]--;
                break;
            }
        }
        if(cambio){
            ll aux = gcdTodos();
            for(long i = 0; i < vec.size(); i++){
                if(vec[i] % aux == 0){
                    vec[i] /= aux;
                }
            }
            if(turno){
                turno = 0;
            }else {
                turno = 1;
            }
            solve();
        }else{
            for(long i = 0; i < vec.size(); i++){
                if(vec[i]!= 1){
                    vec[i]--;
                    break;
                }
            }
            ll aux = gcdTodos();
            for(long i = 0; i < vec.size(); i++){
                if(vec[i] % aux == 0){
                    vec[i] /= aux;
                }
            }
            if(turno){
                turno = 0;
            }else {
                turno = 1;
            }
            solve();
        }
    }
}
int main(){
    long n;
    cin >> n;
    for(long i = 0; i < n; i++){
        ll aux; cin >> aux;
        vec.push_back(aux);
    }

    solve();
    if(!turno){
        cout << "First\n";
    }else{
        cout << "Second\n";
    }

}
