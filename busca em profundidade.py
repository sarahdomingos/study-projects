def valida ():
    pass

def dfs(grafo, vertice, banco, toca, aviao):
    caminho = set()

    def dfs_iterativa(grafo, vertice_fonte):
        caminho.add(vertice_fonte)
        falta_visitar = [vertice_fonte]
        #print(falta_visitar)
        while falta_visitar:
            vertice = falta_visitar.pop()
            for vizinho in grafo[vertice]:
                if vizinho not in caminho:
                    #print(grafo[vertice])
                    #print(vizinho)
                    print(caminho)
                    caminho.add(vizinho)
                    falta_visitar.append(vizinho)
                    #print(falta_visitar)
    dfs_iterativa(grafo, vertice)

grafo = {
    #0: [60, 100, 70, 40],
    60: [60, 100, 70],
    70: [60, 100],
    100: [60, 40],
    40: [100]
}

dfs(grafo, 60, 270, 0, 0)

# aviao - 170 kg;

# piloto - 60 kg;
# guarda - 100 kg;
# chefe - 70 kg;
# dinheiro - 40 kg;

# p1 - 60, 70, 40
# p2 - 60, 70
# p3 - 60, 100
# p4 - 60
# p5 - 60, 70
# p6 - 0