# Independent Sets

Modeling the maximum independent set problem on the undirected graph G = (V,E). Includes two greedy algorithms for finding the maximum independent set.

## Background

#### Coursework in CS 4820

The first question of the problem set covering NP and NP-Completeness asked us to prove that a problem X is NP-hard.
We needed to prove X $\le_p$ Independent Set by transforming the inputs to the Independent Set problem to the inputs to X in polynomial time. 
I incorrectly thought that X would verify it as size k instead of using X to solve Independent Set of size k. But it got me to thinking about approaches to finding the maximum Independent Set. 

## Algorithms

There are two greedy algorithms. Each greedy algorithm has a polynomial time and an exponential time implementation.

The first greedy rule is to select nodes with the least number of neighboring nodes, and delete that node's neighbors until there are no more nodes. The selected nodes form the independent set. We'll call this one "Fewest Neighbors Selected"

The second rule is to remove nodes with the largest number of neighbors and its associated edges until there are no more edges. The remaining nodes in the graph form the independent set. We'll refer to this one as "Most Neighbors Removed"

The difference between the polynomial and exponential time algorithms depend on whether the algorithm explores options when it reaches ties for which node to select next. Whenever there are ties, we would branch into instances that remove a different node from the ones that tie. Looking for the independent set in each tie may find a set closer to the max but in exponential time.


### Most Neighbors Removed - Ties ignored

```
Define Most-Neighbors-Independent-Set:

	Let S be a sortable set of nodes where |S| = |V|

	While E is not empty

		Sort S in decending order of number of edges that are incident to it.

		Remove the first node s' in this sorted order.

		Let E' be the edges incident to s'

		for each e' in E'

			decrement the number of edges incident to the node in e' that is not s'
		
			remove e' from E

	return |S|
```


### Fewest Neighbors Selected - Ties Ignored 


## Input File

The program takes a text file as first argument.

The first line should contain the total number of nodes.

The remaining lines consist of pairs of numbers, the pair of numbers is separated by a space, representing an edge between the numbers

The following input corresponds to a graph of five nodes and five edges.

````
5
0 1
0 4
0 2
2 4
2 3
````
![](graph.png?raw=true)

## Acknowledgements 

CS 4820 Problem Set X

Kleinberg, Jon, and Éva Tardos. Algorithm Design. Pearson, 2014.

[Greedy Algorithm for Maximum Independent Set](https://semidoc.github.io/greedyMIS)

[structs as keys for unordered_sets in c++](https://www.techiedelight.com/use-struct-key-std-unordered_map-cpp/)

[functors with std::sort](https://ideone.com/zJ2ca)