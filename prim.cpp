
#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
vector<vector<pair<int, int>>> G;
int vis[N], dis[N], vid = 0;
int n;

int prim()
{
    vid++;
    memset(dis, 63, n * sizeof(dis[0]));
    dis[0] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(0, 0);
    int result = 0;
    while (q.size())
    {
        int d, u;
        tie(d, u) = q.top();
        q.pop();
        d *= -1;
        if (vis[u] == vid)
            continue;
        vis[u] = vid;
        result += d;
        for (auto p : G[u])
        {
            int v, c;
            tie(v, c) = p;
            if (vis[v] == vid)
                continue;
            if (dis[v] > c)
            {
                dis[v] = c;
                q.emplace(-c, v);
            }
        }
    }
    return result;
}

int main()
{

    cin.tie(0);
    ios::sync_with_stdio(0);

    int m;
    cin >> n >> m;

    G.resize(n);
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        G[--u].emplace_back(--v, w);
        G[v].emplace_back(u, w);
    }
    cout << prim() << "\n";

    return 0;
}