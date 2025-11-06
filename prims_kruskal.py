import heapq
from heapq import heappush, heappop

print("\n--- College Campus Graph Representation ---\n")
num_dept = int(input("Enter number of departments/institutes: "))

departments = []
for i in range(num_dept):
    name = input(f"Enter name of department {i + 1}: ").strip()
    departments.append(name)

adjacency_list = {d: [] for d in departments}
edges = []

print("\nEnter distance between departments (enter -1 if no direct connection):")
for i in range(num_dept):
    for j in range(i + 1, num_dept):
        d = float(input(f"Distance between {departments[i]} and {departments[j]}: "))
        if d != -1:
            edges.append((departments[i], departments[j], d))
            adjacency_list[departments[i]].append((departments[j], d))
            adjacency_list[departments[j]].append((departments[i], d))

INF = float('inf')
adjacency_matrix = [[INF] * num_dept for _ in range(num_dept)]
for i in range(num_dept):
    adjacency_matrix[i][i] = 0

index_of = {departments[i]: i for i in range(num_dept)}
for u, v, w in edges:
    i, j = index_of[u], index_of[v]
    adjacency_matrix[i][j] = adjacency_matrix[j][i] = w

def print_adjacency_list(adj):
    print("\nAdjacency List:")
    for node, neighbours in adj.items():
        print(f"  {node} -> {neighbours}")

def print_adjacency_matrix(matrix, names):
    print("\nAdjacency Matrix:")
    header = "      " + "  ".join(f"{name[:6]:>6}" for name in names)
    print(header)
    for i, row in enumerate(matrix):
        row_str = "  ".join(f"{(int(x) if x != INF else 'INF'):>6}" for x in row)
        print(f"{names[i][:6]:>6}  {row_str}")

def kruskal_mst(nodes, edges):
    edges.sort(key=lambda x: x[2])
    parent = {n: n for n in nodes}
    rank = {n: 0 for n in nodes}
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    def union(a, b):
        ra, rb = find(a), find(b)
        if ra == rb:
            return False
        if rank[ra] < rank[rb]:
            parent[ra] = rb
        elif rank[ra] > rank[rb]:
            parent[rb] = ra
        else:
            parent[rb] = ra
            rank[ra] += 1
        return True
    mst, total = [], 0
    for u, v, w in edges:
        if union(u, v):
            mst.append((u, v, w))
            total += w
        if len(mst) == len(nodes) - 1:
            break
    return mst, total

def prim_mst(adj, start=None):
    if not start:
        start = next(iter(adj))
    visited = set([start])
    heap = []
    for to, w in adj[start]:
        heappush(heap, (w, start, to))
    mst, total = [], 0
    while heap and len(mst) < len(adj) - 1:
        w, u, v = heappop(heap)
        if v in visited:
            continue
        visited.add(v)
        mst.append((u, v, w))
        total += w
        for nxt, wt in adj[v]:
            if nxt not in visited:
                heappush(heap, (wt, v, nxt))
    return mst, total

print_adjacency_list(adjacency_list)
print_adjacency_matrix(adjacency_matrix, departments)

kruskal_edges, kruskal_cost = kruskal_mst(departments, edges)
print("\n--- Minimum Spanning Tree (Kruskal’s Algorithm) ---")
for u, v, w in kruskal_edges:
    print(f"{u} -- {v} : {w}")
print(f"Total Cost = {kruskal_cost}")

start_node = departments[0]
prim_edges, prim_cost = prim_mst(adjacency_list, start=start_node)
print("\n--- Minimum Spanning Tree (Prim’s Algorithm) ---")
for u, v, w in prim_edges:
    print(f"{u} -- {v} : {w}")
print(f"Total Cost = {prim_cost}")

if kruskal_cost == prim_cost:
    print("\nBoth algorithms produced the same total cost.")
else:
    print("\n⚠ Costs differ — check input graph.")
