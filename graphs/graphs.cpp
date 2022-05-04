#include <bits/stdc++.h>
using namespace std;

#define adj(u, v, e, w) for (int e = head[u], v, w; ~e, ((v = to[e], w = wt[e]), 1); e = nxt[e])

typedef long long ll;
typedef vector<int> vint;
const int N = 1000;
int head[N], to[N], nxt[N], wt[N], ne, n;

void init()
{
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}

void addEdge(int f, int t, int w = 1)
{
    to[ne] = t;
    nxt[ne] = head[f];
    wt[ne] = w;
    head[f] = ne++;
}
void addBiEdge(int f, int t, int w = 1)
{
    addEdge(f, t, w);
    addEdge(t, f, w);
}
int main(int argc, char const *argv[])
{

    return 0;
}