#include <iostream>
#include <vector>
#define MAX 10;

using namespace std;

void heapfy(vector<int> &arvore, int n, int i)
{

    int maior = i, esq = 2 * i, dir = 2 * i + 1;

    if (esq < n && arvore[maior] < arvore[esq])
    {
        maior = esq;
    }
    if (dir < n && arvore[maior] < arvore[dir])
    {
        maior = dir;
    }
    if (maior != i)
    {
        int aux = arvore[i];
        arvore[i] = arvore[maior];
        arvore[maior] = aux;
        heapfy(arvore, n, maior);
    }
}

void heapsort(vector<int> &arvore, int n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        heapfy(arvore, n, i);
    }
    for (int i = n-1; i >= 0; i--)
    {
        int aux = arvore[0];
        arvore[0] = arvore[i];
        arvore[i] = aux;
        heapfy(arvore, i, 0);
    }
}

int main (){
    vector<int> arvore;
    int n = MAX;
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        arvore.push_back(valor);
    }
    heapsort(arvore, n);

    for (int i = 0; i < n; i++) {
        cout << arvore[i] << " ";
    }
    cout << endl;
}



/*int main()
{

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arvore (n, vector<int>(0));
    int u, v;
    for (int i = 0; i < m; i++)
    {
        arvore[u].push_back(v);
        arvore[v].push_back(u);
    }


}*/