# Implementación del Algoritmo de Floyd-Warshall

**Materia:** Análisis de Algoritmos  
**Lenguaje:** C  
**Descripción:** Este programa resuelve el problema de "todos los pares de caminos más cortos" (All-Pairs Shortest Paths) en un grafo dirigido y ponderado. Además de calcular los costos mínimos, reconstruye la ruta exacta entre cualquier par de nodos.

---

## 1. Instrucciones de Ejecución

### Compilación
El código es estándar y no requiere librerías externas. Para compilarlo en la terminal:

```bash
gcc main.c -o floyd
```

### Ejecución
**Opción manual:**
```
./floyd
```

**Opción con archivo de entrada:**
```
./floyd < input.txt
```

**Formato de Entrada**

Un número *n* (cantidad de nodos).
La matriz de *n x n* valores (usar *-1* para representar infinito).
3 pares de nodos (origen destino) para probar las rutas al final.

---

## 2. Ejemplo de Resultados (Evidencia)

### Entrada:
```
Numero de nodos: "4"

Ingresa la matriz (-1 = Infinito):
0   5  -1  10
-1  0   3  -1
-1 -1   0   1
-1 -1  -1   0

Ingresa pares 'Origen Destino' (o '0 0' para salir):
"1 3"
Ruta 1 a 3: 1 -> 2 -> 3 (Costo: -2)

"4 2"    
Ruta 4 a 2: No hay camino.

"1 4"
Ruta 1 a 4: 1 -> 2 -> 3 -> 4 (Costo: -1)

"0 0" > Finaliza el programa.
```

### Salida:
```
Numero de nodos: 4
Ingresa la matriz de adyacencia (-1 = Infinito):

[Estado Inicial]
--- Matriz Inicial ---
      0      5    INF     10
    INF      0      3    INF
    INF    INF      0      1
    INF    INF    INF      0

[Resultados Finales]
--- Matriz D (Distancias) ---
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0

--- Matriz R (Recorridos) ---
      0      2      2      2
      0      0      3      3
      0      0      0      4
      0      0      0      0

--- Consultar Rutas ---
Ingresa 3 pares de nodos (Origen Destino) para ver su camino:
Caso 1: Ruta: 1 -> 2 -> 3 (Costo: 8)
Caso 2: Ruta: No hay camino posible.
Caso 3: Ruta: 1 -> 2 -> 3 -> 4 (Costo: 9)
```

---

## 3. Detalles Técnicos
### Complejidad del Algoritmo
El algoritmo utiliza tres ciclos anidados (*for*) que recorren todos los nodos (*1 a n*).

**Tiempo:** *O(n^3)*. Esto se debe a que para cada nodo intermedio *k*, revisamos cada par (*i, j*).
**Espacio:** *O(n^2)*. Utilizamos dos matrices de tamaño *n x n* (*D y R*).
**Limitación:** Debido a la complejidad cúbica, este algoritmo es ideal para grafos pequeños o medianos (hasta unos 400 nodos), pero se vuelve muy lento con grafos masivos.

### Supuestos de Implementación
**Infinito:** Se utiliza el valor *9999999* internamente. En la entrada se pide *-1* por comodidad del usuario.
**Matriz R:** Se inicializa apuntando al destino directo. Si floyd encuentra un atajo por *k*, actualizamos *R[i][j] = R[i][k]*.
**Nodos:** Se manejan índices del *1 al N* para coincidir con la teoría vista en clase.