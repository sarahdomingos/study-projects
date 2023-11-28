def heapfy(array, n, i):
    
    maior = i
    esquerda = 2 * i
    direita = 2 * i + 1
    
    if esquerda < n and array[maior] < array[esquerda]:
        maior = esquerda
    if direita < n and array[maior] < array[direita]:
        maior = direita
    if maior != i:
        array[i], array[maior] = array[maior], array[i]
        heapfy(array, n, maior)
    

def heapsort(array, n):
    
    for i in range(n//2 - 1, -1, -1):
        heapfy(array, n, i)
    
    for i in range(n - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        heapfy(array, i, 0) 


array = [1, 6, 3, 10, 7, 2, 99, 8]
n = len(array)
heapsort(array, n)
print (array)