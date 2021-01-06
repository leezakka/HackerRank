/**
 * Description : Kruscal Algorithm
 * Date : 2020-12-17
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Global Var
int *parent;

// Global Func
int findParent(int idx);
void unionParent(int idx1, int idx2);
bool checkSameParent(int idx1, int idx2);
int getMaxNodeVar(vector<class Edge> v); 
int getMinNodeVar(vector<class Edge> v); 

// Class
class Edge {
  public:
    int node[2];
    int distance;
    Edge( int idx1, int idx2, int distance ) {
      this->node[0] = idx1;
      this->node[1] = idx2;
      this->distance = distance;
    }

    bool operator < (const Edge &edge) const {
      return this->distance < edge.distance;
    }
};

// Function Definition
int findParent(int idx) {
  if(parent[idx] == idx)
    return idx;
  else {
    int y = findParent(parent[idx]);
    parent[idx] = y;
    return y;
  }
} 

void unionParent(int idx1, int idx2) {
  idx1 = findParent(idx1);
  idx2 = findParent(idx2);

  if(idx1 != idx2) {
    if ( idx1 < idx2 )
      parent[idx2] = idx1;
    else
      parent[idx1] = idx2;
  }
}

bool checkSameParent(int idx1, int idx2) {
  idx1 = findParent(idx1);
  idx2 = findParent(idx2);

  if ( idx1 == idx2 )
    return true;
  else
    return false;
}

int getMaxNodeVar(vector<class Edge> v) { 

  int max = v[0].node[1];

  for(int i = 1; i < v.size(); i++) {
    if (max < v[i].node[1] ) {
      max = v[i].node[1];
    } 
  }
  return max;
}

int getMinNodeVar(vector<class Edge> v) { 

  int min = v[0].node[0];

  for(int i = 1; i < v.size(); i++) {
    if (min > v[i].node[0] ) {
      min = v[i].node[0];
    } 
  }
  return min;
}

// Main
int main()
{
  int nodeCnt = 0;
  int minNode = 0;
  int maxNode = 0;
  int kruscalSum = 0;

  vector<Edge> v;

  v.push_back(Edge(0,1,7));
  v.push_back(Edge(1,2,8));
  v.push_back(Edge(0,3,5));
  v.push_back(Edge(1,3,9));
  v.push_back(Edge(1,4,7));
  v.push_back(Edge(2,4,5));
  v.push_back(Edge(3,4,15));
  v.push_back(Edge(3,5,6));
  v.push_back(Edge(4,5,8));
  v.push_back(Edge(4,6,9));
  v.push_back(Edge(5,6,11));
  
  // 1. Sort
  sort(v.begin(), v.end());

  // Get Node Count for Dynamic Allocation
  maxNode = getMaxNodeVar(v);
  minNode = getMinNodeVar(v);
  if (minNode == 0)
    nodeCnt = 1 + maxNode;
  else 
    nodeCnt = maxNode;

  cout << "minNode : " << minNode << endl;
  cout << "maxNode : " << maxNode << endl;
  cout << "nodeCnt : " << nodeCnt << endl;

  // Dynamic Alloc amountted Node Count : default 7
  parent = new int[nodeCnt];


  // 2. Set Parent Table for Union-Find
  for(int i = 0; i < nodeCnt; i ++) {
    parent[i] = i;
  }


  // 3. Run UnionFind to find Kruscal-Tree
  for ( int i = 0; i < v.size(); i ++ ) {

    // minNode = 0 then start 0 index, else 1 index
    if ( minNode == 0) {
      if ( !checkSameParent( v[i].node[0], v[i].node[1] ) ) {
        kruscalSum += v[i].distance;
        unionParent( v[i].node[0], v[i].node[1] );

        // Print Kruskal Root 
        printf("[%d, %d, %d]\n", v[i].node[0], v[i].node[1], v[i].distance); 
      }
    }
    else {
      if ( !checkSameParent( v[i].node[0]-1, v[i].node[1]-1 ) ) {
        kruscalSum += v[i].distance;
        unionParent( v[i].node[0]-1, v[i].node[1]-1 );

        // Print Kruskal Root 
        printf("[%d, %d, %d]\n", v[i].node[0], v[i].node[1], v[i].distance); 
      }
    }
  }

  // 4. Result : Kruscal Sum
  cout << "Kruscal Sum is " << kruscalSum << endl;

  delete[] parent;

  return 0;
}
