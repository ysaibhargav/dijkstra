------------------------------------------------------------------------------------------------------------
Dijkstra's Algorithm with Heaps - CS213 PROGRAMMING ASSIGNMENT 2
------------------------------------------------------------------------------------------------------------
by Sai Bhargav Yalamanchi - 11D070060 25/11/2012

Input - G(V, E)
First line - number of nodes in the graph (|V| <= 1024)
Followed by |V| chunks, where chunk i consists of mi+1 lines,
of which the first line is the number mi, the out degree of vertex vi (0 <= vi < |V|).
The next mi lines consist of two numbers vj (one of vi's neighbours) and wij (weight of edge vi-vj >= 0).

Output -
|V| lines, where ith line is of form -
i --> d(S, i)
where d(S, i) is the shortest path distance between the source S and the vertex i that the 
algorithm computes.

Sample - 
INPUT
3
2
1 2
2 3
0
0

OUTPUT
0 --> 0
1 --> 2
2 --> 3

Note:
Below is the implementation of the algorithm.
I have used binary heaps as the priority queue data structure
for efficient extract mins and decrease key operations.
The heap has been implemented by means of arrays.
I have used the map data structure to link the nodes of the graph
with their positions in the array, to avoid pointer logic in my code.
In any heap function call, the map is used for about O(1) times.
Each map operation takes about O(lg |V|) time, therefore, the asymptotic
run time of the heap function remains the same. 
(Each insert, extract min, decrease key operation takes O(lg |V|) time.)

Time complexity - O((|V|+|E|)lg |V|).
