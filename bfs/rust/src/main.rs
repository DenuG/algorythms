// use std::collections::VecDeque;
use std::fs::File;
use std::io::{BufReader, Read};

const INF: i32 = i32::MAX;

fn bfs(graph: &Vec<Vec<i32>>, start: usize) -> Vec<i32> 
{
    let mut dist = vec![INF; graph.len()];
    let mut q = std::collections::VecDeque::new();
    let mut from = vec![-1; graph.len()];

    dist[start] = 0;
    q.push_back(start);

    while !(q.is_empty())
    {
        let v = q.pop_front().unwrap();
        q.pop_front();
    
        for to in graph[v].clone()
        {
            if dist[to as usize] > dist[v] + 1
            {
                dist[to as usize] = dist[v] + 1;
                from[to as usize] = v as i32;
                q.push_back(to as usize);
            }
        }
    }
    from
}



fn get_path(from: &Vec<i32>, finish: i32) -> Vec<i32>
{
    let mut path = Vec::new();
    // for v: i32 = finish; v != -1; v = from[v as usize] 
    let mut v = finish;
    while v != -1
    {
        path.push(v);
        v = from[v as usize];    
    }
    path.reserve(path.len());
    path
}


fn main() 
{
    let file = File::open("/src/graph.txt").expect("Failed to open file");
    let mut reader = BufReader::new(file);

    let mut input = String::new();
    reader.read_to_string(&mut input).expect("Failed to read from file");

    let mut lines = input.lines();

    let vertex_count: usize = lines.next().unwrap().parse().unwrap();
    let edge_count: usize = lines.next().unwrap().parse().unwrap();

    let mut graph = vec![vec![]; vertex_count];

    for _ in 0..edge_count {
        let line = lines.next().unwrap();
        let parts: Vec<i32> = line.split_whitespace().map(|x| x.parse().unwrap()).collect();
        let a = parts[0];
        let b = parts[1];

        graph[a as usize].push(b);
        graph[b as usize].push(a);
    }

    let start = lines.next().unwrap().parse().unwrap();

    let from = bfs(&graph, start);

    for v in get_path(&from, 4) {
        print!("{} ", v);
    }
}
