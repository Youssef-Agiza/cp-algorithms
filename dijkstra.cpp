#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

#define adj(u, e, v, w) for (int e = head[u], v, w; ~e && ((v = to[e], w = wt[e]), 1); e = nxt[e])
const int N = 10000 + 5, M = 10000 + 5;
int head[N], to[M], nxt[M], wt[M];
int ne, n, m;

int dist[N];
void init()
{
    memset(head, -1, n * sizeof(head[0]));
    // memset(wt, INT_MAX, m * sizeof(wt[0]));
    ne = 0;
}

void addEdge(int f, int t, int w)
{
    to[ne] = t;
    wt[ne] = w;
    nxt[ne] = head[f];
    head[f] = ne++;
}
void addBiEdge(int f, int t, int w)
{
    addEdge(f, t, w);
    addEdge(t, f, w);
}

void dijkstra(int src)
{
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;

    priority_queue<pair<int, int>> PQ;
    PQ.emplace(-dist[src], src);
    while (PQ.size())
    {
        int u, d;
        tie(d, u) = PQ.top();
        PQ.pop();
        d = -d;
        if (dist[u] != d)
            continue;
        adj(u, e, v, w)
        {
            if (!~dist[v] || w + d < dist[v])
            {
                dist[v] = w + d;
                PQ.emplace(-dist[v], v);
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}