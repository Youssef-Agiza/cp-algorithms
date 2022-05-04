#include <bits/stdc++.h>
using namespace std;

#define REP(i, st, e) for (int i = st; i < e; i++)
#define REPI(i, st, e) for (int i = e; i >= st; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

#define adj(u, e, v) for (int e = head[u], v; ~e && (v = to[e], 1); e = nxt[e])
const int N = 1000 + 5, M = 1000 + 5;
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
int vid, curTime, numCmp, compId[N], vis[N], id[N], low[N];
stack<int> st;

void tarjan(int u)
{
    compId[u] = -1;
    vis[u] = vid;
    id[u] = low[u] = curTime++;
    st.push(u);

    adj(u, e, v)
    {
        if (vis[v] != vid)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!(~compId[v])) // visited and still on stack
            low[u] = min(low[u], low[v]);
    }
    if (id[u] == low[u]) // start of scc
    {
        int x;
        do
        {
            x = st.top();
            st.pop();
            compId[x] = numCmp;

        } while (x != u);
        numCmp++;
    }
}

void tarjan()
{
    vid++, numCmp = curTime = 0;

    REP(u, 0, n)
    if (vis[u] != vid)
        tarjan(u);
}
int main(int argc, char const *argv[])
{

    return 0;
}