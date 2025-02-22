#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <vector>
#include <Eigen/Dense>

class DijkstraVisualizer : public QWidget {
public:
    DijkstraVisualizer(const std::vector<Eigen::Vector3i>& points, const std::vector<float>& distances, QWidget* parent = nullptr)
        : QWidget(parent), points(points), distances(distances) {}

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Draw points
        for (const auto& point : points) {
            painter.setBrush(Qt::green);
            painter.drawEllipse(QPoint(point[0], point[1]), 5, 5);
        }

        // Draw lines representing distances
        painter.setPen(Qt::black);
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                if (distances[i] != std::numeric_limits<float>::max() && distances[j] != std::numeric_limits<float>::max()) {
                    painter.drawLine(QPoint(points[i][0], points[i][1]), QPoint(points[j][0], points[j][1]));
                }
            }
        }
    }

private:
    std::vector<Eigen::Vector3i> points;
    std::vector<float> distances;
};

void visualizeDijkstra(const std::vector<Eigen::Vector3i>& points, const std::vector<float>& distances) {
    int argc = 0;
    char* argv[] = {nullptr};
    QApplication app(argc, argv);

    DijkstraVisualizer visualizer(points, distances);
    visualizer.resize(800, 600);
    visualizer.setWindowTitle("Dijkstra Visualization");
    visualizer.show();

    app.exec();
} 