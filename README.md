# Important points to remember while doing graph problems:

## BFS :
* Starts at the root node and explores all the nodes at the present depth before moving on to the next depth level. 

* Typically uses a queue data structure to store the child nodes.
## DFS :
* Starts at the root node and explores as far as possible before backtracking to the previous node.
* Uses recursive approach
* Useful in fiding connected components

## Bipartite graph :
* A graph which can be colored using only 2 colors such that no two adjacent nodes are of same color.
* Can be found using both BFS and DFS

## Topological sorting :
* Linear ordering of vertices such that if there is an edge u->v, u appears before v in that ordering.
* DFS can be used with the help of a stack data structure.
* BFS is more efficient in finding topological sorted order due to its iterative nature.

