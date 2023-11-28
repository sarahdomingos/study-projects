#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void print_caminho(vector<int>& pai, int v)
{
	if(pai[v] != v)
		print_caminho(pai, pai[v]);

	cout << v << " ";

}

void bfs( vector<vector<int> >& adj, vector<int>& fontes)
{

	int n = adj.size();
	vector<int> num(n, -1);
	vector<int> pai(n, -1);
	vector<int> dist(n, -1);

	int cnt = 0;

	queue<int> fila;

	for(int i=0; i< fontes.size(); i++)
	{
		fila.push(fontes[i]);

		pai[fontes[i]] = fontes[i];
		num[fontes[i]] = cnt++;
		dist[fontes[i]] = 0;
	}

	while (not fila.empty())
	{
		int v = fila.front();
		fila.pop();


		for(int i = 0; i < adj[v].size(); i++)
		{
			int w = adj[v][i];
			if( num[w] == -1)
			{
				num[w] = cnt++;
				pai[w] = v;
				dist[w] = dist[v] + 1;
				fila.push(w);
			}
		}
	}


	 cout << "NUMS\n"; 
	 for(int i=0; i<n; i++) 
	 	cout << i << " " << num [i] << endl; 

	 cout << "PAIS\n"; 
	 for(int i=0; i<n; i++) 
	 	cout << i << " " << pai[i] << endl; 

	 cout << "DIST\n"; 
	 for(int i=0; i<n; i++) 
	 	cout << i << " " << dist[i] << endl; 

	//print_caminho(pai, f);
}


int main()
{

	int n, m;

	cin >> n >> m;

	vector<vector<int> > adj(n, vector<int> ());
	vector<int> fontes {0};

	int u, v;
	for(int i=0; i<m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(adj,fontes);
	 for(int i=0; i<n;i++) 
	 	cout << adj[i].size() << endl; 

}
