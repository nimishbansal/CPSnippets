#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll mod = 998244353;
const long mxN = 1000000;
const ld error = 1e-8;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll

inline ll MOD(ll x, ll m = mod)
{
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1e18+1;
const int nmax = bt(17);
///===========================================  template  =======================================================
ll modexpo(ll x, ll n, ll m = mod){
    ll ret = 1%m;
    while(n){
        if(n&1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}

ll fac[nmax];
ll facinv[nmax];


ll NCR(int n, int r){
    if(n < r) return 0;
    return fac[n] * facinv[r] % mod * facinv[n-r] % mod;
}

long long iv[1 +mxN];

void precal()
{

    iv[1]=1;
	for(int i=2; i<=mxN; ++i)
		iv[i]=mod-(mod/i)*(iv[mod%i])%mod;


    fac[0] = 1;
    for(int i = 1; i<nmax; i++)
        fac[i] = (fac[i-1]*i) % mod;
    facinv[nmax-1] = modexpo(fac[nmax-1], mod-2);
    for(int i = nmax-1; i>0; i--)
        facinv[i-1] = (facinv[i]*i) % mod;
    return;
}

// iv = modular inverse
// f1 = factorial modulo
//f2 = factorial modulo inverse, facinv
// https://www.geeksforgeeks.org/modular-multiplicative-inverse-1-n/
// https://discuss.codechef.com/t/mdswin2-editorial/56712 EDitorialist solution

// iv[1]=1;
// 	for(int i=2; i<=mxN; ++i)
// 		iv[i]=M-M/i*iv[M%i]%M;
// 	f1[0]=f2[0]=1;
// 	for(int i=1; i<=mxN; ++i) {
// 		f1[i]=f1[i-1]*i%M;
// 		f2[i]=f2[i-1]*iv[i]%M;
// 	}
// 436731905 935854081 811073537 811073537
// 10, 1,

long long gcdExtended(long long a, long long b, long long *x, long long *y);
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

// Function to compute a/b under modlo m
long long modDivide(long long a, long long b, long long m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1){
        cout << "Division not defined";
        return -1;
    }
    else{}
       // cout << "Result of division is " << (inv * a) % m;

    return (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
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
int main(){
    precal();
    cout << modDivide(3, 16, mod) << endl;
}
