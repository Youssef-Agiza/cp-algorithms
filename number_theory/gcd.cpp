#include <bits/stdc++.h>
using namespace std;

#define REP(i, st, e) for (int i = st; i < e; i++)
#define REPI(i, st, e) for (int i = e; i >= st; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

int gcd1(int a, int b)
{
    return b ? gcd1(b, a % b) : a;
}
int gcd2(int a, int b)
{
    while (b)
        a %= b, swap(a, b);

    return a;
}
int lcm(int a, int b)
{
    return (a / gcd1(a, b)) * b;
}
/*
If both numbers are even, then we can factor out a two of both and compute the GCD of the remaining numbers: gcd(2a,2b)=2gcd(a,b) .
If one of the numbers is even and the other one is odd, then we can remove the factor 2 from the even one: gcd(2a,b)=gcd(a,b) if b is odd.
If both numbers are odd, then subtracting one number of the other one will not change the GCD: gcd(a,b)=gcd(b,a-b)
*/
int gcdOptimized(int a, int b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

// find x,y Such that a.x + b.y= gcd(a,b)
/*
    a.x +b.y= gcd(a,b)
    b.x1+
*/
ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll res = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return res;
}

int main(int argc, char const *argv[])
{
    cout << gcd1(20, 4) << "\n";
    cout << gcd2(20, 4) << "\n";
    cout << lcm(20, 5) << "\n";

    ll x, y;
    extendedGCD(24, 3, x, y);

    return 0;
}