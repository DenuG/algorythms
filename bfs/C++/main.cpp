#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

const int INF = 1e9;

std::vector<int> bfs(const std::vector<std::vector<int>>& graph, int start)
{
    std::vector<int> dist(graph.size(), INF);
    std::vector<int> from(graph.size(), -1);
    std::queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int to : graph[v])
        {
            if (dist[to] > dist[v] + 1)
            {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }
    return from;
}

std::vector<int> getPath(const std::vector<int>& from, int finish)
{
    std::vector<int> path;
    for (int v = finish; v != -1; v = from[v])
    {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main()
{
    freopen("graph.txt", "r", stdin);

    int vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    std::vector<std::vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    std::cin >> start;

    std::vector<int> from = bfs(graph, start);


    for (int v: getPath(from, 4))
    {
        std::cout << v << " ";
    } // => 0 3 2 4

    return 0;
}
