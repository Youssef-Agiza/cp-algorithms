

#include <bits/stdc++.h>
using namespace std;

#define REP(i, st, e) for (int i = st; i < e; i++)
#define REPI(i, st, e) for (int i = e; i >= st; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

bool isPrime(ll n)
{
    if (n == 2)
        return true;
    if (!(n & 1) || n == 1)
        return false;

    for (ll i = (ll)3; i * i <= n; i += 2)
        if (!(n % i))
            return false;

    return true;
}
/*
finds the number of time n! contains p.
e.g. if n=6--> n!= 2*3*4*5*6= 2(4) * 3(2) * 5
*/
int findPow(int n, int p)
{
    int res = 0;
    while (n)
        res += n /= p;
    return res;
}

int main(int argc, char const *argv[])
{
    return 0;
}