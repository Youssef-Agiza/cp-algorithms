#include <bits/stdc++.h>
using namespace std;

#define REP(i, st, e) for (int i = st; i < e; i++)
#define REPI(i, st, e) for (int i = e; i >= st; i--)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

#define adj(u, e, v) for (int e = head[u], v; ~e && (v = to[e], 1); e = nxt[e])
const int N = int(2e6) + 5, M = int(2e6) + 5;
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

int Not(int a)
{
    return a ^ 1;
}

void addOr(int a, int b)
{
    // add);
    addEdge(Not(a), b);
    addEdge(Not(b), a);
}
void addXor(int a, int b)
{
    addOr(a, b);
    addOr(Not(a), Not(b));
}

int rooms_states[M];
int main(int argc, char const *argv[])
{

    int rooms, switches, c, d;
    vector<vint> vec;
    cin >> rooms >> switches;
    vec.resize(rooms);
    n = switches * 2;
    init();
    REP(i, 0, rooms)
    {
        cin >> rooms_states[i];
    }
    REP(i, 0, switches)
    {

        cin >> c;
        while (c--)
        {
            cin >> d;
            vec[--d].push_back(i);
        }
    }
    int x, y;
    REP(i, 0, rooms)
    {
        x = vec[i][0], y = vec[i][1];
        if (rooms_states[i])
        {
            addOr(Not(x), y);
            addOr(Not(y), x);
        }
        else
            addXor(x, y);
    }
    tarjan();
    int i;
    for (i = 0; i < n; i += 2)
        if (compId[i] == compId[i + 1])
        {
            cout << "NO\n";
            exit(0);
        }

    cout << "YES\n";
    return 0;
}