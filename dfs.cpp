#include <iostream>
#include <vector>

using namespace std;

int cnt;

vector<int> pre;
vector<int> cc;
vector<int> pai;
int qnt_comp_conx;

void DFSrec(vector<vector<int>> &adj, int v)
{

    pre[v] = cnt++;
    cc[v] = qnt_comp_conx;

    /* for(int w : adj[v]) */
    for (int i = 0; i < adj[v].size(); i++)
    {
        int w = adj[v][i];
        if (pai[w] == -1)
        {
            pai[w] = v;
        }

        if (pre[w] == -1) // Se não vi
            DFSrec(adj, w);
    }
}

void DFS(vector<vector<int>> &adj)
{
    cnt = 0;
    int n = adj.size();

    // Crio um vetor com n posições e inicilize com -1

    for (int v = 0; v < n; v++)
    {
        if (pre[v] == -1)
        {
            if (pai[v] == -1)
            {
                pai[v] = v;
            }
            DFSrec(adj, v);
            qnt_comp_conx++;
        }
    }
}

int main()
{

    qnt_comp_conx = 0;

    int n, m;
    cin >> n >> m;

    pre = vector<int>(n, -1);
    cc = vector<int>(n, -1);
    pai = vector<int>(n, -1);

    // cout << "n m " << n << " " << m;

    vector<vector<int>> adj(n, vector<int>(0));
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //DFS(adj);

    //for (int i = 0; i < n; i++)
    //    cout << i << " " << cc[i] << " " << pre[i] << " " << pai[i] << endl;

    //cout << "qnt_comp_conx = " << qnt_comp_conx << endl;
}
