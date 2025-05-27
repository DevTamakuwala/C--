/*
 * In this code we will be creating a graph using adjacency list
 * To create a graph we will be creating a class called Edge
 * in this class we will be creating a constructor which will take the source and destination of the edge
 * The adjacency list is a kind of list which is list of lists meansing it will store the neighbours list inside the list
 * To create the graph first we have to make the graph empty
 * then we will add the edges to the graph
 * We will be using the ArrayList class to create the graph
 */
package Graph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;


class graphMain{

    static class Edge {

        int src;
        int dest;
        int weight;

        public Edge(int src, int dest, int weight){
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        public Edge(int src, int dest){
            this.src = src;
            this.dest = dest;
        }
    }

    public static void createGraph(ArrayList<Edge> grap[]){
        for (int i = 0; i < grap.length; i++) {
            grap[i] = new ArrayList<Edge>();
        }

        /*grap[0].add(new Edge(0, 2, 2));
        
        grap[1].add(new Edge(1, 2, 10));
        grap[1].add(new Edge(1, 3, 0));
        
        grap[2].add(new Edge(2, 0, 2));
        grap[2].add(new Edge(2, 1, 10));
        grap[2].add(new Edge(2, 3, -1));
        
        grap[3].add(new Edge(3, 1, 0));
        grap[3].add(new Edge(3, 2, -1));*/

        // grap[0].add(new Edge(0, 1));
        // grap[0].add(new Edge(0, 2));

        // grap[1].add(new Edge(1, 0));
        // grap[1].add(new Edge(1, 3));

        // grap[2].add(new Edge(2, 0));
        // grap[2].add(new Edge(2, 4));

        // grap[3].add(new Edge(3, 1));
        // grap[3].add(new Edge(3, 4));
        // grap[3].add(new Edge(3, 5));

        // grap[4].add(new Edge(4, 2));
        // grap[4].add(new Edge(4, 3));
        // grap[4].add(new Edge(4, 5));

        // grap[5].add(new Edge(5, 3));
        // grap[5].add(new Edge(5, 4));
        // grap[5].add(new Edge(5, 6));

        // grap[6].add(new Edge(6, 5));

        // grap[0].add(new Edge(0, 2));
        // grap[1].add(new Edge(1, 0));
        // grap[2].add(new Edge(2, 3));
        // grap[3].add(new Edge(3, 0));


        // grap[0].add(new Edge(0, 1));
        // grap[0].add(new Edge(0, 4));

        // grap[1].add(new Edge(1, 0));
        // grap[1].add(new Edge(1, 2));
        // // grap[1].add(new Edge(1, 4));
        
        // grap[2].add(new Edge(2, 1));
        // grap[2].add(new Edge(2, 3));

        // grap[3].add(new Edge(3, 2));
        
        // grap[4].add(new Edge(4, 0));
        // // grap[4].add(new Edge(4, 1));
        // grap[4].add(new Edge(4, 5));
        
        // grap[5].add(new Edge(5, 4));

        grap[0].add(new Edge(0, 1, 2));
        grap[0].add(new Edge(0, 2, 4));

        grap[1].add(new Edge(1, 3, 7));
        grap[1].add(new Edge(1, 2, 1));
        
        grap[2].add(new Edge(2, 4, 3));
        
        grap[3].add(new Edge(3, 5, 1));
        
        grap[4].add(new Edge(4, 3, 2));
        grap[4].add(new Edge(4, 5, 5));

    }

    /*
    * In breath First Search the thumd rule is to visit neighbour first.
    * in this first we will create some inportant variables which are queue and array of visited elements.
    * in the queue first we will add the first element or 0 for starting then we will start the while loop until the queue is empty
    * in this while loop we will remove the element from the queue and check the value for that element in the visited
    * array. If the element is already visited then it's value will be true else false
    * so if the value is false then we will print it and then mark it's position as true in the visited array
    * and the we will run another loop inside the while loop which will add the neighbours of the removed element from the in the queue
    * as we remove the elements in the queue there will be a state when all the elements are searched and the queue is empty and then
    * out while loop will be ended
    */
    public static void BSF(ArrayList<Edge> graph[], int V){
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[V];

        q.add(0);

        while (!q.isEmpty()) {
            int curr = q.remove();
            if (!visited[curr]) {
                
                System.out.print(curr+" ");
                
                visited[curr] = true;

                for(int i = 0; i < graph[curr].size(); i++){
                    q.add(graph[curr].get(i).dest);
                }
            }
        }
    }


    /*
    * In depth First Search the thumd rule is to visit all the neighbours in depth first.
    * To do this we will be creating a recursive function which will take the graph, current node and the visited array
    * in this function we will first print the current node and then mark it as visited
    * then we will run a loop for the neighbours of the current node and check if the neighbour is already visited
    * if it is not then we will call the function again with the neighbour as the current node
    * this will continue until all the neighbours are visited and then the function will return to the previous node
    * and then the loop will continue for the next neighbour
    * this will continue until all the nodes are visited and then the function will return to the main function
    */
    public static void DFS(ArrayList<Edge> graph[], int curr, boolean visited[]){
        System.out.print(curr+" ");
        visited[curr] = true;

        for(int i = 0; i <graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(!visited[e.dest]){
                DFS(graph, e.dest, visited);
            }
        }
    }


    /*
     * This is to check if there is any cycle exist in the directed graph or not
     * In this method we are having various attributes like graph the visited array of booleans, integer type current,
     * recursive array to check the cycle.
     * 
     * As we enter in the method first we will mark current in visited and recursive as true that means that is in the call stack in recursion
     * then we will run another loop to check the neighbours and during that there will be a condition to if the current edge neighbour is
     * true in the recursive call stack that means it's a cycle and will return true.
     * And if that is not the case then it will go in the else if block in which if there will be the current edge  neighbour is true in
     * visited array if it is true the we will recall it method and if the method returns true then we will return true.
     * at the end of the for loop we will change the recursive array of the current value to false and return false.
     * This will check if there is any cycle or not if there is any cycle the method will retun the true and if there is not a cycle
     * then the method will return false.
     */
    public static boolean isCycleDirected(ArrayList<Edge> graph[], boolean[] visited, int curr, boolean rec[]){
        visited[curr] = true;
        rec[curr] = true;

        for(int i = 0; i <graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if (rec[e.dest]) {
                return true;
            }
            else if (!visited[e.dest]) {
                if (isCycleDirected(graph, visited, e.dest, rec)) {
                    return true;
                }
            }
        }
        
        rec[curr] = false;
        return false;
    }

    public static boolean isCycleUndirected(ArrayList<Edge> graph[], boolean visited[], int curr, int parent){
        visited[curr] = true;

        for (int i = 0; i < graph[curr].size(); i++) {
            Edge e = graph[curr].get(i);
            if (visited[e.dest] && e.dest != parent) {
                return true;
            } else if(!visited[e.dest]){
                if (isCycleUndirected(graph, visited, e.dest, curr)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static class Pair implements Comparable<Pair>{
        int node;
        int dest;

        public Pair(int n, int d){
            this.dest = d;
            this.node = n;
        }

        @Override
        public int compareTo(Pair o) {
            return this.dest - o.dest;
        }
    }

    public static void dijkstra(ArrayList<Edge> graph[], int src, int V){
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int dest[] = new int[V];
        for(int i = 0; i<V; i++){
            if (i != src) {
                dest[i] = Integer.MAX_VALUE;
            }
        }

        boolean vis[] = new boolean[V];

        pq.add(new Pair(0, 0));
        
        while (!pq.isEmpty()) {
            Pair curr = pq.remove();
            if (!vis[curr.node]) {
                vis[curr.node] = true;

                for(int i = 0; i < graph[curr.node].size(); i++){
                    Edge e = graph[curr.node].get(i);
                    int u = e.src;
                    int v = e.dest;
                    if (dest[u] + e.weight < dest[v]) {
                        dest[v] = dest[u] + e.weight;
                        pq.add(new Pair(v, dest[v]));
                    }
                }
            }
        }

        for (int i = 0; i < V; i++) {
            System.out.print(dest[i]+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int V = 6;
        ArrayList<Edge> graph[] = new ArrayList[V];

        createGraph(graph);



        // BSF(graph, V);
        // System.out.println();

        // DFS(graph, 0, new boolean[V]);

        // System.out.println();

        // System.out.println(isCycleDirected(graph, new boolean[V], 0, new boolean[V]));

        System.out.println(isCycleUndirected(graph, new boolean[V], 0, -1));

        // Show all neghibours for 2
        // for(int i = 0; i < graph[2].size(); i++){
        //     Edge e = graph[2].get(i);
        //     // System.out.println(e.src+" -> "+e.dest+" with "+e.weight+" weight");
        //     System.out.println(e.src+" -> "+e.dest);
        // }

        dijkstra(graph, 0, V);
    }
}