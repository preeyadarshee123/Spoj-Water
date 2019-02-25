# Spoj-Water Editorial
My approach is to calculate how much water can be stored on the surface of each cuboidal surface.
This can be done in the following way :
1. If we are able to find the maximum height in the minimum height pathway from each point to boundary, then 
 The water stored will be equal to the maximum height of all the node's in this path.
 
 Ty to visualise this on a piece of paper using the example test case given in the problem.
 
 2. this minimum height pathway can be calculated using priority queue each time pushing the neighbour's element height 
 3 . when we arrive at the boundary . we stop .
 4  all the nodes on this minimum pathway can be found by just backtracking along the its parent node until we find the source node .
 5. in this minimum pathway , calculate the maximum value of node's height .
 add value of ( maximum - value of node) to the answer . 
