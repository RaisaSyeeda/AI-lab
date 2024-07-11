#include<bits/stdc++.h>
using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2) {
   return abs(x1 - x2) + abs(y1 - y2);// This calculates the Manhattan distance (h(n)) between two points.
}


int main(){

    map<char,pair<int,int>> mp; //mp: A map that stores the coordinates (x, y) of each node. / Store coordinates (x, y) of nodes.



    map<char,pair<int,int>>::iterator it1;
    map<pair<char,char>, int> mp1;//mp1: A map that stores the cost between pairs of nodes. // Store costs between pairs of nodes.


    map<char,int>vis;//vis: A map to track visited nodes.
    map<pair<char,char>, int>::iterator it;


    vector<char>adj[30];//adj: An array of vectors to store adjacency information. graph e adj list banate hoy, ekta node er shathe kara connected
    //26 letters

    /*
    The mp map is populated with coordinates of nodes/node er pos
    The mp1 map is populated with costs between pairs of nodes.
    Additionally, the adjacency list is populated based on the edges defined in mp1.*/
    mp['A'] = {1,9};
    mp['E'] = {7,11};
    mp['J'] = {12,10};
    mp['C'] = {5,8};
    mp['H'] = {9,8};
    mp['F'] = {6,6};
    mp['I'] = {10,6};
    mp['N'] = {4,5};
    mp['B'] = {2,4};//(index, value)
    mp['K'] = {8,3};
    mp['G'] = {4,2};
    mp['D'] = {11,2};
    mp['L'] = {9,1};
    mp['M'] = {12,1};
    mp['S'] = {2,7};

    //actual cost, bidirectiona
    mp1[{'S','A'}] = 20;
    mp1[{'S','B'}] = 30;
    mp1[{'S','C'}] = 30;
    mp1[{'A','E'}] = 60;
    mp1[{'B','G'}] = 30;
    mp1[{'C','N'}] = 50;
    mp1[{'N','F'}] = 40;
    mp1[{'G','K'}] = 50;
    mp1[{'F','I'}] = 50;
    mp1[{'K','I'}] = 50;
    mp1[{'K','L'}] = 30;
    mp1[{'L','D'}] = 30;
    mp1[{'D','M'}] = 20;
    mp1[{'J','D'}] = 100;
    mp1[{'H','D'}] = 90;
    mp1[{'E','H'}] = 50;
    mp1[{'E','J'}] = 60;
    mp1[{'N','K'}] = 60;
    mp1[{'C','E'}] = 30;

    //map<char,string>parent;



    for(it = mp1.begin(); it!=mp1.end(); it++){   // Populate adjacency list (adj)
        /*Populating the Adjacency List (adj):
        This loop iterates through the mp1 map, which contains pairs of nodes as keys and their corresponding costs as values.

        For each pair (a, b) in mp1, where a and b are characters representing nodes:
        a and b are used as indices to access the adj array of vectors.
        The value of 'A' is subtracted from a and b to convert characters to integer indices (e.g., 'A' - 'A' = 0, 'B' - 'A' = 1, and so on).
        The push_back method is used to add b to the adjacency list of node a and vice versa, indicating that there is an edge between a and b.
        */
        char a = it->first.first;//it.first-->index, second->cost
        char b = it->first.second;
        int cost = it->second;
        //mp1[{b,a}] = cost;

        adj[a-'A'].push_back(b); //next A te adj B store //a = 'A'-'A'=0, b='C'-'A'=2, index push korbo  // Add edge from a to b.
        adj[b-'A'].push_back(a); // B te adj A store // Add edge from b to a (bidirectional).
    }

    for(it = mp1.begin(); it!=mp1.end(); it++){// Repopulate mp1 with reverse pairs
        /*Repopulating mp1 with Reverse Pairs:
        This loop iterates through the mp1 map again.
        For each pair (a, b) in mp1:
        The code constructs a new pair {b, a} (essentially swapping a and b) and assigns the original cost to this reversed pair.
        This operation effectively adds the reverse edge to the mp1 map, so that both (a, b) and (b, a) are present with the same cost.*/
        char a = it->first.first;
        char b = it->first.second;
        int cost = it->second;

        mp1[{b,a}] = cost;//// Add the reverse edge with the same cost.
    }


    char strt, ed;//start node, end node
    cin >> strt >> ed;



    priority_queue<pair<int,pair<char,int>>>pq;//priority queue pq is initialized to store pairs of (heuristicValue, (node, cost)).// Priority queue to store nodes and their costs.

    pq.push({0, {strt, 0}});//first-->h(n), second(node(nijer), cost(ettuk ashte kemon porse)) ,Initialize the queue with the starting node and zero cost.
    int coun = 0;


    while(pq.size()){//algo implement, // While the priority queue is not empty.


        char node = pq.top().second.first;// Current node.
        int current_cost = pq.top().second.second;// Current cost to reach this node.

        cout << current_cost <<" "<<node<< endl;//print each step

        pq.pop();
        vis[node] = 1;// Mark the node as visited.

        if( node == ed){
            cout << "Reached Goal, Cost: "<<current_cost<<endl;
            break;// If the goal is reached, terminate the search.
        }

        for( int i = 0; i < adj[node-'A'].size(); i++){
            char next = adj[node-'A'][i];//adj er node
    /*
    The search algorithm was implemented here.
    The loop continues as long as there are nodes in the priority queue.

    In each iteration:
    The top element (heuristicValue, (node, cost)) is extracted from the priority queue.
    The current node is marked as visited, and if it's the goal node (ed), the program terminates.
    For each neighbor of the current node:
    If the neighbor has not been visited yet, calculate its heuristic value using the Manhattan distance.
    Calculate the new cost to reach the neighbor and push it into the priority queue with the updated cost and heuristic value.
    */


            if( vis[next]==0){//vis kina , 0 mane no
                int x = mp[next].first; //x,y next node er ps
                int y = mp[next].second;// x-coordinate of the neighboring node. -coordinate of the neighboring node.

                int l = mp[ed].first;//goal pos
                int r = mp[ed].second;// x-coordinate of the goal node. y-coordinate of the goal node.

                int heuristicValue = manhattanDistance(x, y, l, r);

                //cout << heuristicValue <<" "<<next<<" "<<node<<endl;
                //cout << x <<" "<<y<<" "<<l<<" "<<r<<endl;

                // Now Calculate heuristic value using Manhattan distance
                // Update next_cost and push into the priority queue
                int next_cost = current_cost + mp1[{node,next}];//current cost ->node porjonto ashte, mp1 next porjonto jaite // Calculate cost to reach the neighboring node.
                pq.push({-heuristicValue, {next, next_cost}});//pq te save hoy b0ro to choto tai ulta jate choto to boro pai,  // Push the neighboring node into the queue.
            }
        }


    }




}
