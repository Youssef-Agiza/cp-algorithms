#include <bits/stdc++.h>
using namespace std;

#define TRAV_SET(j, st, dsu) for (int j = dsu.roots[st]; ~j; j = dsu.nxt[j])

typedef long long ll;
typedef vector<int> vint;
const int N = 1000;

struct DSU
{

    int parent[N], sz[N], n, num_of_comp;
    int roots[N], roots_inv[N];
    int tail[N], nxt[N];

    void init(int s)
    {
        num_of_comp = (n = s);

        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);

        iota(roots, roots + n, 0);
        iota(roots_inv, roots_inv + n, 0);

        iota(tail, tail + n, 0);
        iota(nxt, nxt + n, 0);
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool join(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (b == a)
            return false;

        if (sz[a] > sz[b]) // a is smaller
            swap(a, b);

        parent[a] = b;
        sz[b] += sz[a];

        int posA = roots_inv[a];
        int elementToBeMoved = roots[--num_of_comp];
        int elementToBeMovedOldPos = roots_inv[num_of_comp];
        roots[posA] = elementToBeMoved;
        roots_inv[elementToBeMovedOldPos] = posA;

        nxt[tail[b]] = a;
        tail[b] = tail[a];
        return true;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
