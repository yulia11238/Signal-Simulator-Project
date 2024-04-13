#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

// Widget class for the UI
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);  // Set up the widget
    ~Widget();  // Clean up

private slots:
    void on_frequencySlider_valueChanged(int value);
    void on_amplitudeSlider_valueChanged(int value);

private:
    void updateGraph();  // Method to update the chart based on slider values

    Ui::Widget *ui;                    // Pointer to the UI setup
    QChartView *m_chartView;           // For displaying the chart
    QSplineSeries *m_frequencySeries;  // Series for frequency
    QSplineSeries *m_amplitudeSeries;  // Series for amplitude
};

#endif // WIDGET_H
