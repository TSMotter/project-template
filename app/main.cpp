#include <CXXGraph/CXXGraph.hpp>
#include <memory>

class GeoCoordinates
{
   public:
    GeoCoordinates()
    {
    }
    GeoCoordinates(float lat, float lon) : m_lat{lat}, m_lon{lon}
    {
    }
    ~GeoCoordinates()
    {
    }

    bool operator==(const GeoCoordinates &that) const
    {
        return (this->m_lat == that.m_lat && this->m_lon == that.m_lon);
    };

    friend std::istream &operator>>(std::istream &input, GeoCoordinates &coord)
    {
        return input >> coord.m_lat >> coord.m_lon;
    }

    float m_lat;
    float m_lon;
};

std::ostream &operator<<(std::ostream &os, const GeoCoordinates &coord)
{
    os << "Lat: " << coord.m_lat << " Lon: " << coord.m_lon;
    return os;
}

int main()
{
    // Each node represents a waypoint (address) along a hypothetical route in
    // Chicago.
    CXXGraph::Node<GeoCoordinates> node0("Grant Park", std::move(GeoCoordinates{41.8796, 87.6237}));
    CXXGraph::Node<GeoCoordinates> node1("Near West Side",
                                         std::move(GeoCoordinates{41.8806, 87.6634}));
    CXXGraph::Node<GeoCoordinates> node2("Pilsen", std::move(GeoCoordinates{41.8560, 87.6567}));

    std::cout << "This is node0: " << node0 << std::endl;

    // Each edge represents a possible route between 2 waypoints, where weights
    // represents the traffic intensity
    CXXGraph::UndirectedWeightedEdge<GeoCoordinates> edge0_1_a(1, node0, node1, 2.0);
    CXXGraph::UndirectedWeightedEdge<GeoCoordinates> edge0_1_b(2, node0, node1, 4.0);
    CXXGraph::UndirectedWeightedEdge<GeoCoordinates> edge1_2_a(3, node1, node2, 1.0);
    CXXGraph::UndirectedWeightedEdge<GeoCoordinates> edge1_2_b(4, node1, node2, 0.5);

    CXXGraph::T_EdgeSet<GeoCoordinates> edgeSet;
    edgeSet.insert(std::make_shared<CXXGraph::UndirectedWeightedEdge<GeoCoordinates>>(edge0_1_a));
    edgeSet.insert(std::make_shared<CXXGraph::UndirectedWeightedEdge<GeoCoordinates>>(edge0_1_b));
    edgeSet.insert(std::make_shared<CXXGraph::UndirectedWeightedEdge<GeoCoordinates>>(edge1_2_a));
    edgeSet.insert(std::make_shared<CXXGraph::UndirectedWeightedEdge<GeoCoordinates>>(edge1_2_b));

    // Can print out the edges for debugging
    std::cout << edge0_1_a << "\n";
    std::cout << edge0_1_b << "\n";
    std::cout << edge1_2_a << "\n";
    std::cout << edge1_2_b << "\n";

    CXXGraph::Graph<GeoCoordinates> graph(edgeSet);
    auto                            res = graph.dijkstra(node0, node2);

    std::cout << "Dijkstra Result: ";
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) << res.result
              << std::endl;
    return 0;
}
