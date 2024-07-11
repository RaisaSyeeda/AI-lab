#include<bits/stdc++.h>
using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2) {
   return abs(x1 - x2) + abs(y1 - y2);
}
/*This code uses the A* search algorithm with a specific heuristic(Manhattan distance, cost, and current heuristic value) to find the shortest path between two nodes in a graph.
It employs a priority queue for efficient exploration of nodes.
*/
/*
g(n) is represented by the current_cost variable.
h(n) is calculated using the manhattanDistance function and the coordinates of nodes.
*/

int main(){

    int threshold = 1e9;
    int ans = 0;
    map<char,pair<int,int>> mp;
    map<char,pair<int,int>>::iterator it1;
    map<pair<char,char>, int> mp1;

    map<char,int>vis;
    map<pair<char,char>, int>::iterator it;

    //Maps mp and mp1 store nodes' coordinates and costs, respectively.
    //The adjacency lists adj represent the graph's structure.

    vector<char>adj[30];

    mp['A'] = {1,9};
    mp['E'] = {7,11};
    mp['J'] = {12,10};
    mp['C'] = {5,8};
    mp['H'] = {9,8};
    mp['F'] = {6,6};
    mp['I'] = {10,6};
    mp['N'] = {4,5};
    mp['B'] = {2,4};
    mp['K'] = {8,3};
    mp['G'] = {4,2};
    mp['D'] = {11,2};
    mp['L'] = {9,1};
    mp['M'] = {12,1};
    mp['S'] = {2,7};

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

    map<char,string>parent;

    for(it = mp1.begin(); it!=mp1.end(); it++){
        char a = it->first.first;
        char b = it->first.second;
        int cost = it->second;

        //mp1[{b,a}] = cost;

        adj[a-'A'].push_back(b);
        adj[b-'A'].push_back(a);
    }

    for(it = mp1.begin(); it!=mp1.end(); it++){
        char a = it->first.first;
        char b = it->first.second;
        int cost = it->second;

        mp1[{b,a}] = cost;
    }


    char strt, ed;
    cin >> strt >> ed;

    priority_queue<pair<int,pair<char,int>>>pq;//A priority queue pq is initialized to store pairs of (heuristicValue, (node, cost)).
    pq.push({0, {strt, 0}});//The starting node strt is pushed into the priority queue with initial cost 0. A* is implemented here using the priority queue.

    int coun = 0;

    //A Search Algorithm:*
    while(pq.size()){

        char node = pq.top().second.first;
        int current_cost = pq.top().second.second;
        int current_h = pq.top().first * -1;
        pq.pop();
        vis[node] = 1;//update visited status

        if ( current_cost > threshold) continue;//boro hole skip korba

        cout << current_h <<" "<<threshold<<" "<<node<< endl;

        for( int i = 0; i < adj[node-'A'].size(); i++){
            char next = adj[node-'A'][i];// Check for unvisited nodes
            // Calculate heuristicValue, next_cost
            // Update priority queue
            // Update threshold and ans if goal is reached

            if( vis[next]==0){
                int x = mp[next].first;
                int y = mp[next].second;

                int l = mp[ed].first;
                int r = mp[ed].second;

                int heuristicValue = manhattanDistance(x, y, l, r) + mp1[{node, next}] + current_cost;

                //cout << heuristicValue <<" "<<next<<" "<<node<<endl;
                //cout << x <<" "<<y<<" "<<l<<" "<<r<<endl;

                int next_cost = current_cost + mp1[{node,next}];
                pq.push({-heuristicValue, {next, next_cost}});

                if (next == ed){
                    if (threshold > next_cost){
                        threshold = next_cost;
                        ans = next_cost;
                        //cout <<"****"<<" "<<next<<" "<<heuristicValue<<" "<<next_cost<<endl;
                    }
                }

            }
        }

    } /*The algorithm iterates while the priority queue is not empty.
    The top element (heuristicValue, (node, cost)) is extracted from the priority queue.
    If the current_cost is greater than the threshold, the loop continues (pruning).
    For each neighbor next of the current node:
    If the neighbor is unvisited:
        Calculate the heuristic value (heuristicValue) based on the Manhattan distance, cost, and current heuristic value.
        Calculate the new cost to reach the neighbor (next_cost).
        Push the new pair (-heuristicValue, (next, next_cost)) into the priority queue.
        Update threshold and ans if the goal node is reached.*/

    cout << ans <<endl;




}

