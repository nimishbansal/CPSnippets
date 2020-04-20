#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

// Exponentiation Modulo
long long modexpo(long long x, long long n, long long m = M){
    /*
    Calculates (x ^ n) mod m for very large n as well
    logarithmic complexity for 10^18 as well
    */
    long long ret = 1%m;
    while(n){
        if(n&1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}


inline int add(int a, int b, int mod) { return ((a % mod) + (b % mod)) % mod; }
inline int sub(int a, int b, int mod) { return ((a % mod) - (b % mod) + mod) % mod; }
inline int mul(int a, int b, int mod) { return ((a % mod) * (b % mod)) % mod; }

/* Modulo Multiplication
    (P * Q) modulo M = ((P modulo M) * (Q modulo M)) modulo M
*/


/* Modulo Division
    it is same as modulo Multiplication if we convert 1/Q to modulo Inverse of Q
    therefore
        (P / Q) modulo M = ((P modulo M) * (modInverse(Q) modulo M)) modulo M
        and to calculate inverse it requires extended GCD algorithm
*/

long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

long long modInverse(long long b, long long m)
{
    long long x, y; // used in extended GCD algorithm
    long long g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}

int main(){
    return 0;
}
