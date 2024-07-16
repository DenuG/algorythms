package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const INF int = 1e9

func bfs(graph [][]int, start int) []int {
	dist := make([]int, len(graph))
	from := make([]int, len(graph))
	q := make([]int, 0)

	for i := 0; i < len(graph); i++ {
		dist[i] = INF
		from[i] = -1
	}

	dist[start] = 0
	q = append(q, start)

	for len(q) > 0 {
		v := q[0]
		q = q[1:]

		for _, to := range graph[v] {
			if dist[to] > dist[v]+1 {
				dist[to] = dist[v] + 1
				from[to] = v
				q = append(q, to)
			}
		}
	}
	return from
}

func getPath(from []int, finish int) []int {
	var path []int
	for v := finish; v != -1; v = from[v] {
		path = append(path, v)
	}
	for i, j := 0, len(path)-1; i < j; i, j = i+1, j-1 {
		path[i], path[j] = path[j], path[i]
	}
	return path
}

func readLine(scanner *bufio.Scanner) (int, int) {
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	return a, b
}

func main() {
	file, err := os.Open("graph.txt")
	if err != nil {
		panic(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)

	vertexCount, edgeCount := readLine(scanner)

	graph := make([][]int, vertexCount)
	for i := 0; i < vertexCount; i++ {
		graph[i] = make([]int, 0)
	}

	for i := 0; i < edgeCount; i++ {
		a, b := readLine(scanner)
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}

	scanner.Scan()
	line := scanner.Text()
	start, _ := strconv.Atoi(line)

	from := bfs(graph, start)
	fmt.Println(getPath(from, 4)) // => 0 3 2 4
}
