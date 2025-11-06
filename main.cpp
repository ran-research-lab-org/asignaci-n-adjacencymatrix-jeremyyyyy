#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);

  G.print();

 cout << endl << G.numEdges() << endl;
 cout << G.inDegree(9) << endl;
 cout << G.inDegree(0) << endl;
 cout << G.isInfluencer(9) << endl;
 cout << G.isInfluencer(0) << endl;
}
