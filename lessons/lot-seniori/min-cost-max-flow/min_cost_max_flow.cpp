using flow_t = int;

struct Edge {
    int from, to;
    flow_t capacity, flow, cost;
    Edge(int from, int to, flow_t capacity, flow_t cost)
        : from(from), to(to), capacity(capacity), flow(0), cost(cost) {}
};

// Min-cost max-flow via Dijkstra with Johnson potentials
struct MinCostMaxFlow {
    int V, E = 0;
    vector<vector<int>> g;
    vector<Edge> edges;
    vector<flow_t> h, dis;
    vector<int> pre;

    MinCostMaxFlow(int V) : V(V), E(0), g(V) {}

    void addEdge(int from, int to, flow_t capacity, flow_t cost) {
        g[from].push_back(E++);
        edges.emplace_back(from, to, capacity, cost);
        g[to].push_back(E++);
        edges.emplace_back(to, from, 0, -cost);
    }

    bool dijkstra(int source, int sink) {
        dis.assign(V, numeric_limits<flow_t>::max());
        pre.assign(V, -1);
        priority_queue<pair<flow_t, int>, vector<pair<flow_t, int>>, greater<>> pq;
        dis[source] = 0;
        pq.emplace(0, source);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dis[u] != d) continue;
            for (int i : g[u]) {
                if (edges[i].flow == edges[i].capacity) continue; // saturated
                int v = edges[i].to;
                flow_t w = edges[i].cost + h[u] - h[v]; // reduced cost >= 0
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pre[v] = i;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis[sink] != numeric_limits<flow_t>::max();
    }

    // Returns {max_flow, min_cost}
    pair<flow_t, flow_t> flow(int source, int sink) {
        h.assign(V, 0);
        flow_t total_flow = 0, total_cost = 0;
        while (dijkstra(source, sink)) {
            for (int i = 0; i < V; i++) h[i] += dis[i]; // update potentials
            flow_t aug = numeric_limits<flow_t>::max();
            for (int i = sink; i != source; i = edges[pre[i] ^ 1].to)
                aug = min(aug, edges[pre[i]].capacity - edges[pre[i]].flow);
            for (int i = sink; i != source; i = edges[pre[i] ^ 1].to) {
                edges[pre[i]].flow += aug;
                edges[pre[i] ^ 1].flow -= aug;
            }
            total_flow += aug;
            total_cost += aug * h[sink]; // h[sink] = real cost of this path
        }
        return {total_flow, total_cost};
    }
};
