#include <bits/stdc++.h>
using namespace std;

#define adj(u, v, e) for (int e = head[u], v; ~e && ((v = to[e]), 1); e = nxt[e])
const int N = 10000 + 5, M = 1000000 + 5;
int head[N], to[M], nxt[M], ne, n;

void init()
{
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}

void addEdge(int f, int t)
{
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

int res[N], resSz = 0, indeg[N];
void topological_sort()
{
    priority_queue<int> Q;
    for (int i = 0; i < n; i++)
        if (!indeg[i])
            Q.push(-i);

    resSz = 0;
    while (Q.size())
    {
        // cout << "here\n";
        int u = -Q.top();
        Q.pop();
        res[resSz++] = u;
        adj(u, v, e)
        {
            // cout << "here2\n";

            if (!--indeg[v])
                Q.push(-v);
        }
    }
}

typedef long long ll;
typedef vector<int> vint;

int main(int argc, char const *argv[])
{
    int m, a, b;
    cin >> n >> m;
    init();

    while (m--)
    {
        cin >> a >> b;
        addEdge(--a, --b);
        indeg[b]++;
    }
    topological_sort();

    if (resSz != n)
        cout << "No solution.\n";
    else
        for (int i = 0; i < resSz; i++)
            cout << res[i] + 1 << " \n"[i + 1 == n];

    return 0;
}