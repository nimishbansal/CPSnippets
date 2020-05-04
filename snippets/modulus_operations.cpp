#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
const int mxN = 10000000;
long long fac[1 + mxN], facinv[1 + mxN], iv[1 +mxN];
// fac stores factorial modulo mod
// factinv stores modular inverse of factorial modulo mod
// iv stores moular inverse modulo mod


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

long long modInverseModPrime(long long b, long long m)
{
    // Fermat little Theorem https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
    return modexpo(b, m - 2, m);
}


void precal()
{

    iv[1]=1;
	for(int i=2; i <= mxN; ++i)
		iv[i] = M -(M/i)*(iv[M%i])%M;


    fac[0] = 1;
    for(int i = 1; i<mxN; i++)
        fac[i] = (fac[i-1]*i) % M;

    facinv[mxN-1] = modexpo(fac[mxN-1], M-2);

    for(int i = mxN-1; i>0; i--)
        facinv[i-1] = (facinv[i]*i) % M;

    return;
}


long long NCR(long long n, long long r, long long mod = M){
    //Finds numbers of ways selecting r objects from n objects modulus mod
    // before using this function is necessary to precalculate values outf
    // fact and facinv (therefore precal must be used)

    if(n < r) return 0;
    // simply n! * 1/(r!)   *  1/(n - r)!
    return fac[n] * facinv[r] % mod * facinv[n-r] % mod;
}



int main(){
    precal();
    cout << iv[52345] << endl;
    cout << modInverseModPrime(52345, M) << endl;
    return 0;
}
