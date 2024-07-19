from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            queue.extend([neighbor for neighbor in graph[node] if neighbor not in visited])
    return visited


graph = {
    "a": ["b", "c"],
    "b": ["a", "d"],
    "c": ["a", "d"],
    "d": ["e"],
    "e": ["d"],
}

print(bfs(graph, "a"))
print(bfs(graph, "e"))
print(bfs(graph, "c"))