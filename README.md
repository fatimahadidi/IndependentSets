# Independent Sets

Implementing a different greedy algorithms for finding an independent set for a basic undirected graph G = (V,E) close to the maximum independent set.

## Background

#### Coursework in CS 4820

We began the topic on NP and NP-Completeness. One of the questions on the first problem set on the topic introduced us to proving a problem X is NP-hard.
We were proving X $\le_p$ Independent Set and so needed to transform the inputs to the Independent Set problem to the inputs to X in polynomial time. 
The transformation of the input G = (V,E) I decided on was more of a find a max independent set that X would verify it as size k instead of using X to solve Independent Set of size k.
But this got me to think about approaches to finding the max Independent Set. 

## Algorithms

There are two polynomial time and two exponential time greedy algorithms, where each greedy method has a polynomial time and an exponential time implementation.

The first greedy rule is to select nodes with the least number of nodes, and delete that node's neighbors until there are no more nodes.
The second rule is to remove nodes with the largest number of neighbors and its associated edges until there are no more edges.

The difference between the polynomial and exponential time algorithms depend on whether the algorithm explore the options when it reaches ties.Whenever there are ties, branch into instances that remove a different node from the ones that tie. Looking for the independent set in each tie may find a set closer to the max but in exponential time. 


### Most Neighbors Removed
---

#### Ties ignored

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
	endFor
endWhile

return |S|
```

#### Ties Explored


#### Fewest Meighbors Selected
---

#### Ties Ignored 

#### Exploring Ties

## Input File

The program takes a text file as first argument.

The first line should contain the total number of nodes.

For the next N lines, line n contains the id's of nodes that share an edge with n, delimited by " ".

The following input corresponds to a graph of five nodes and five edges.

````
5
1 2 4
0
0 3 4
2
0 2
````
![](graph.png?raw=true)

## Acknowledgements 

CS 4820 Problem Set X

Kleinberg, Jon, and Éva Tardos. Algorithm Design. Pearson, 2014.

[Greedy Algorithm for Maximum Independent Set](https://semidoc.github.io/greedyMIS)

[structs as keys for unordered_sets in c++](https://www.techiedelight.com/use-struct-key-std-unordered_map-cpp/)



