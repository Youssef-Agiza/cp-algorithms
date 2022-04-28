#include <bits/stdc++.h>
using namespace std;

#define REP(i, st, e) for (int i = st; i < e; i++)
#define REPI(i, st, e) for (int i = e; i >= st; i--)
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;

#define adj(u, e, v) for (int e = head[u], v; ~e && (v = to[e], 1); e = nxt[e])
const int N = 1000 + 5, M = 1000 + 5;
int head[N], to[M], nxt[M], deg[N], ne, n;
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
int vis[M], res[M], m, resSize = 0, vid = 0;

void _euler(int u)
{
    adj(u, e, v)
    {
        if (vis[v] == vid)
            continue;
        vis[v] = vid;
        _euler(v);
        res[resSize++] = e;
    }
}

inline bool hasOddDegree()
{
    return find(deg, deg + n, vid) != deg + n;
}

bool euler(int u)
{
    if (hasOddDegree())
        return false;

    _euler(u);
    return resSize == m;
}

int main(int argc, char const *argv[])
{

    cin >> n >> m;
    init();
    vid++;

    int u, v;
    REP(i, 0, m)
    {
        cin >> u >> v;
        addEdge(u, v);
        deg[u] = deg[u] == vid ? 0 : vid;
        deg[v] = deg[v] == vid ? 0 : vid;
    }
    if (!euler(0))
        cout << "graph doesn't have euler path\n";
    else
        REPI(i, 0, resSize - 1)
            cout << res[i] << " ";

    return 0;
}