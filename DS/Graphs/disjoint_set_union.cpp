#include <bits/stdc++.h>
using namespace std;

class disjoint
{
private:
    int n;
    vector<int> parent;
    vector<int> rank;
    /*rank represents the intial height of the tree
    Intially all the nodes are connected to themselves, that mean parent of node is node itself
    */
public:
    disjoint(int _n)
    {
        n = _n;
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            // making parent of node to node itself
            rank.push_back(0);
            // intially the rank of all teh nodes is zero
        }
    }
    /* This finds the ulitmate parent of the node,here the path compression  occurs, if we do not make the path compression then time complexity becomes o(logn)
    parent[node] = findparent(parent[node]) this line does the path compression.
    If we don't want to do the path compression, just only want to find the ultimate parent then simply return the findParent(parent[node])

    Code without path compression looks like
        if(node == parent[node])
        return node;
        return findParent(parent[node]);
    In this scenario the Time complexity would be logn for finding the parent and logn for the making union.
    */
    int findparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    } 
    void unions(int node1, int node2)
    {
        int up1 = findparent(node1);
        int up2 = findparent(node2);
        /*If the both the parents equal,then they belong to same component so no need to make union*/
        if(up1 != up2) 
        {
            if (rank[up1] > rank[up2])
              parent[up2] = up1;
            else if (rank[up2] > rank[up1])
                parent[up1] = up2;
            else
            {
                parent[up2] = up1;
                rank[up1]++;
            }
        }
    } 
    bool checkcomponent(int node1, int node2)
    {
        return findparent(node1) == findparent(node2);
    }
    /* Time complexity of find and union  O(4K) i.e constant
      where k is nearly equal to 1
   union and find operation can be done in constant time,hence they are widely used in competative programming */
}; 

int main()
{
    int n;
    cout << "enter the no of nodes" << endl;
    cin >> n;
    disjoint dj(n);
    /* given two nodes we can make the union of these two nodes
       for the given node we can find the parent
       For the given two nodes we can check whether they belong to same component or not .
       if the parent of two node is same then they belong to same component else not.
    */
} 
