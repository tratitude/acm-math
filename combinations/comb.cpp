/*
Links: https://www.cnblogs.com/linyujun/p/5199684.html
*/
#include<cstdio>
typedef long long LL;
const int N = 100000 + 5;
LL mul(LL a, LL b, LL p){//快速乘，计算a*b%p 
    LL ret = 0;
    while(b){
        if(b & 1) ret = (ret + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ret;
}
LL fact(int n, LL p){//n的阶乘求余p 
    LL ret = 1;
     for (int i = 1; i <= n ; i ++) ret = ret * i % p ;
    return ret ;
}
void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d){
    if (!b) {d = a, x = 1, y = 0;}
    else{
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
LL inv(LL t, LL p){//如果不存在，返回-1 
    LL d, x, y;
    ex_gcd(t, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}
LL comb(int n, int m, LL p){//C(n, m) % p
    if (m < 0 || m > n) return 0;
    return fact(n, p) * inv(fact(m, p), p) % p * inv(fact(n-m, p), p) % p;
}
LL Lucas(LL n, LL m, int p){
        return m ? Lucas(n/p, m/p, p) * comb(n%p, m%p, p) % p : 1;
}
LL china(int n, LL *a, LL *m){//中国剩余定理 
    LL M = 1, ret = 0;
    for(int i = 0; i < n; i ++) M *= m[i];
    for(int i = 0; i < n; i ++){
        LL w = M / m[i];
        //ret = (ret + w * inv(w, m[i]) * a[i]) % M;//这句写了会WA，用下面那句 
        ret = (ret + mul(w * inv(w, m[i]), a[i], M)) % M;
        //因为这里直接乘会爆long long ,所以我用快速乘(unsigned long long也是爆掉，除非用高精度)
    }
    return (ret + M) % M;
}
int main(){
    int T, k;
    LL n, m, p[15], r[15];
    scanf("%d", &T);
    while(T--){
        scanf("%I64d%I64d%d", &n, &m, &k);
        for(int i = 0; i < k; i ++){
            scanf("%I64d", &p[i]);
            r[i] = Lucas(n, m, p[i]);
        }
        printf("%I64d\n", china(k, r, p));
    }
}