#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define REP(i, st, e) for (int i = st; i < e; i++)
#define REPI(i, st, e) for (int i = e; i >= st; i--)
typedef long long ll;
typedef pair<int, int> pii;

typedef vector<int> vint;
const int N = int(2e6) + 5, M = int(2e6) + 5;
bool rooms_states[N];
int n;
vector<vector<int>> adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v)
{
    used[v] = true;
    for (int u : adj[v])
    {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl)
{
    comp[v] = cl;
    for (int u : adj_t[v])
    {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT()
{
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i)
    {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2)
    {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb)
{
    // na and nb signify whether a and b are to be negated
    a = 2 * a ^ na;
    b = 2 * b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

void addOr(int x, int y)
{
    add_disjunction(x, 1, y, 0);
    add_disjunction(x, 0, y, 1);
}

int main(int argc, char const *argv[])
{

    int rooms, switches, c, d;
    vector<vint> vec;
    cin >> rooms >> switches;
    vec.resize(rooms);
    n = switches * 2;
    REP(i, 0, rooms)
    {
        cin >> rooms_states[i];
    }
    REP(i, 0, switches)
    {
        cout << "1\n";

        cin >> c;
        while (c--)
        {
            cin >> d;
            vec[--d].push_back(i + 1);
        }
        cout << "2\n";
    }
    int x, y;
    REP(i, 0, rooms)
    {
        x = vec[i][0], y = vec[i][1];
        if (rooms_states[i])
        {
            add_disjunction(x, 1, y, 0);
            add_disjunction(x, 0, y, 1);
        }
        else
        {
            add_disjunction(x, 0, y, 0);
            add_disjunction(x, 1, y, 1);
        }
    }

    cout << (solve_2SAT() ? "YES" : "NO") << "\n";

    return 0;
}