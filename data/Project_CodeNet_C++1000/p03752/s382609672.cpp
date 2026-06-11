#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i < (int)(n); i++)
using namespace std;

typedef long long ll; // -9,223,372,036,854,775,808 から 9,223,372,036,854,775,807

template <class T> using vec = std::vector<T>;
template <class T> using vec2 = vec<vec<T>>;
template <class T> using vec3 = vec<vec<vec<T>>>;

// #define DEBUG

template <class T>
class InfNum{
    T num;
    int flag_inf; // 1, 0, or -1
    InfNum(T num, int flag_inf){
        this->num = num;
        this->flag_inf = flag_inf;
    }
    public:
    InfNum(): InfNum(0, 0){}
    InfNum(T num): InfNum(num, 0){}

    std::string toString(){
        if(flag_inf == 1){
            return std::string("+Inf");
        }else if(flag_inf == -1){
            return std::string("-Inf");
        }else{
            return std::to_string(this->num);
        }
    }
    
    static InfNum embed(T num){
        return InfNum(num, 0);
    }

    static InfNum posInf(){
        return InfNum(0, 1);
    }

    static InfNum negInf(){
        return InfNum(0, -1);
    }

    bool isFinite() const{
        return this->flag_inf == 0;
    }

    bool operator==(const InfNum<T>& rhs) const{
        if(this->isFinite() && rhs.isFinite()){
            return this->num == rhs.num;
        }else if(!this->isFinite() && !rhs.isFinite()){
            return this->flag_inf == rhs.flag_inf;
        }else{
            return false;
        }
    }

    bool operator!=(const InfNum<T>& rhs) const{
        return !(*this == rhs);
    }

    bool operator<(const InfNum<T>& rhs) const{
        if(this->isFinite()){
            if(rhs.isFinite()){
                return this->num < rhs.num;
            }else{
                switch(rhs.flag_inf){
                    case 1:
                    return true;
                    break;
                    case -1:
                    return false;
                    break;
                    default:
                    throw std::runtime_error("unexpected flag");
                }
            }
        }else{
            // lhs is infinite
            if(rhs.isFinite()){
                return !(rhs < *this);
            }else{
                return this->flag_inf < rhs.flag_inf;
            }
        }
    }

    bool operator<=(const InfNum<T>& rhs) const{
        return (*this == rhs) || (*this < rhs);
    }

    bool operator>(const InfNum<T>& rhs) const{
        return !(*this <= rhs);
    }

    bool operator>=(const InfNum<T>& rhs) const{
        return !(*this < rhs);
    }

    InfNum<T> operator-() const{
        if(this->isFinite()){
            return InfNum<T>::embed(-this->num);
        }else{
            return InfNum<T>(0, -this->flag_inf);
        }
    }

    InfNum<T> operator+(const InfNum<T>& rhs) const{
        if(this->isFinite()){
            if(rhs.isFinite()){
                return InfNum<T>::embed(this->num + rhs.num);
            }else{
                return rhs;
            }
        }else{
            if(rhs.isFinite()){
                return rhs + *this;
            }else{
                if(this->flag_inf == rhs.flag_inf){
                    return *this;
                }else{
                    throw std::runtime_error("Adding +Inf and -Inf is prohibited.");
                }
            }
        }
    }

    InfNum<T> operator-(const InfNum<T>& rhs) const{
        return *this + (-rhs);
    }

    InfNum<T> operator*(const InfNum<T>& rhs) const{
        if(this->isFinite()){
            if(rhs.isFinite()){
                return InfNum<T>::embed(this->num * rhs.num);
            }else{
                if(this->num == 0){
                    return InfNum<T>::embed(0);
                }else if(this->num > 0){
                    return rhs;
                }else if(this->num < 0){
                    return -rhs;
                }else{
                    throw std::runtime_error("cannot happen!");
                }
            }
        }else{
            if(rhs.isFinite()){
                return rhs*(*this);
            }else{
                return InfNum<T>(0, this->flag_inf*rhs.flag_inf);
            }
        }
    }

    InfNum<T> operator/(const InfNum<T>& rhs) const{
        if(this->isFinite()){
            if(rhs.isFinite()){
                return InfNum<T>::embed(this->num / rhs.num);
            }else{
                return InfNum<T>::embed(0);
            }
        }else{
            if(rhs.isFinite()){
                if(rhs.flag_inf >= 0){
                    return *this;
                }else{
                    return -(*this);
                }
            }else{
                throw std::runtime_error("Inf/Inf is prohibited.");
            }
        }
    }


    T raw(){
        if(this->flag_inf != 0){
            throw std::runtime_error("Cannot convert inifinity to a raw value.");
        }
        return this->num;
    }
};
typedef InfNum<ll> ILL;

template <class T>
class Bitvector{
    private:
    T val;
    public:
    static const int MAX = 64;
    Bitvector(T v = 0){
        val = v;
    }

    static Bitvector<T> ones(int len){
        return Bitvector<T>((1 << len) - 1);
    }

    static Bitvector<T> onehot(int pos){
        return Bitvector<T>(1 << pos);
    }

    static Bitvector<T> full(){
        return Bitvector<T>(-1);
    }

    bool is_empty(){
        return val == 0;
    }

    bool is_any(){
        return !is_empty();
    }

    Bitvector<T> operator&(const Bitvector<T>& rhs) const{
        return Bitvector<T>(val & rhs.val);
    }

    Bitvector<T> operator|(const Bitvector<T>& rhs) const{
        return Bitvector<T>(val | rhs.val);
    }

    Bitvector<T> operator~() const{
        return Bitvector<T>(~val);
    }

    bool operator==(const Bitvector<T>& rhs) const{
        return val == rhs.val;
    }

    bool operator!=(const Bitvector<T>& rhs) const{
        return val != rhs.val;
    }


    Bitvector<T> c() const{
        return ~(*this);
    }

    Bitvector<T> operator-(const Bitvector<T>& rhs) const{
        return (*this) & ~rhs;
    }

    bool is_subset_of(const Bitvector<T>& rhs) const{
        // A ⊂ B は A-B = empty
        return (*this - rhs).is_empty();
    }

    bool operator<=(const Bitvector<T>& rhs) const{
        return is_subset_of(rhs);
    }

    bool operator>=(const Bitvector<T>& rhs) const{
        return rhs <= *this;
    }

    int operator[](int n) const{
        return (val >> n) & 1;
    }

    int next_bit(int n){
        for(int i=n+1; i < MAX; i++){
            if((*this)[i]){
                return i;
            }
        }
        return MAX;
    }

    int first_bit(){
        return next_bit(-1);
    }

    // もうないならfullをかえす
    Bitvector<T> get_next_subset(const Bitvector<T>& rhs){
        for(auto i=Bitvector<T>(rhs.val + 1); i <= full(); i++){
            if(i <= *this){
                return i;
            }
        }
        return full();
    }

    void go_next_subset(Bitvector<T>& rhs){
        auto n = get_next_subset(rhs);
        rhs = n;
    }

    int bits(){
        int res = 0;
        for(int i=0; i < MAX; i++){
            if((*this)[i]){
                res++;
            }
        }
        return res;
    }

    Bitvector<T> operator++(int n){
        return Bitvector<T>(val++);
    }

    Bitvector<T> on(int pos) const{
        return (*this) | onehot(pos);
    }

    
    Bitvector<T> off(int pos) const{
        return (*this) - onehot(pos);
    }


    string toString(int len){
        string s;
        for(int i=len - 1; i >= 0; i--){
            s += '0' + (*this)[i];
        }

        return s;
    }

    T raw(){
        return val;
    }
};
typedef Bitvector<long long> BV;

// for(int j=i.first_bit(); j < N; j=i.next_bit(j)){
//     for(int k=i.next_bit(j); k < N; k=i.next_bit(k)){
//         // iのたってるビットのペアをつくる
//     }
// }

// for(auto i=BV(); i <= BV::ones(N); i++){
//     // すべてのサブセットをなめる
// }


// for(auto i=BV(); i <= S; S.go_next_subset(i)){
//     // すべてのサブセットをなめる
// }

ll calc(BV bits, vec<ll> a){
    #ifdef DEBUG
    printf("*START: calc\n");
    cout << bits.toString(a.size()) << endl;
    printf("*END: calc\n");
    #endif
    ll maxHeight = a[0];
    ll res = 0;
    for(int i=1; i < a.size(); i++){
        if(bits[i] == 1){
            ll cost = (maxHeight + 1) - a[i];
            if(cost >= 0){
                res += cost;
                maxHeight++;
            }else{
                maxHeight = max(maxHeight, a[i]);
            }
        }else{
            maxHeight = max(maxHeight, a[i]);
        }
        #ifdef DEBUG
        printf("*START: maxheight\n");
        cout << maxHeight << endl;
        printf("*END: maxheight\n");
        #endif
        
    }
    return res;
}


int main(){
    int Nbuilding, Nneed;
    cin >> Nbuilding >> Nneed;

    vec<ll> a(Nbuilding);
    for(int i=0; i < Nbuilding; i++){
        cin >> a[i];
    }

    auto res = ILL::posInf();
    for(auto i=BV(); i <= BV::ones(Nbuilding); i++){
        if(i.bits() < Nneed){
            continue;
        }
        res = min(res, ILL(calc(i, a)));
    }

    cout << res.raw() << endl;

    return 0;
}