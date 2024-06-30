#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

const int INF = 1e9;

std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>> &graph, int start)
{
    std::vector<int> dist(graph.size(), INF);
    std::vector<int> from(graph.size(), -1);
    dist[start] = 0;

    std::set<std::pair<int, int>> uv; // uv means unvisited vertices
    uv.insert({dist[start], start});

    while (!uv.empty())
    {
        int nearest = uv.begin()->second;
        uv.erase(uv.begin());

        for (auto [to, weight] : graph[nearest])
        {
            if (dist[to] > dist[nearest] + weight)
            {
                uv.erase({dist[to], to});
                dist[to] = dist[nearest] + weight;
                from[to] = nearest;
                uv.insert({dist[to], to});
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

    std::vector<std::vector<std::pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++)
    {
        int a, b, weight;
        std::cin >> a >> b >> weight;

        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }

    int start;
    std::cin >> start;

    std::vector<int> from = dijkstra(graph, start);

    for (int v : getPath(from, 13))
        std::cout << v << " ";

    return 0;
}
