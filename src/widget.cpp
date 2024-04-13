#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>

// Set up the UI and initialize the chart components
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  m_frequencySeries = new QSplineSeries(); // Series for plotting frequencies
  m_amplitudeSeries = new QSplineSeries(); // Series for plotting amplitude

  QChart *chart = new QChart();

  // Add series to the chart
  chart->addSeries(m_frequencySeries);
  chart->addSeries(m_amplitudeSeries);

  // Automatically create and attach axes based on the series' data
  chart->createDefaultAxes();

  chart->setTitle("Frequency vs Amplitude"); // Set chart title
  chart->setBackgroundBrush(Qt::black);
  chart->legend()->setVisible(true);

  // Set the range for X-axis
  QValueAxis *axisX =
      qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).at(0));
  if (axisX) {
    axisX->setRange(0, 360);
    axisX->setTitleText("Degrees");
  }

  // Set the range for Y-axis
  QValueAxis *axisY =
      qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
  if (axisY) {
    axisY->setRange(-1, 1);
    axisY->setTitleText("Amplitude");
  }

  m_chartView =
      new QChartView(chart, ui->chartPlaceholder); // Initialize the chart view
  m_chartView->setRenderHint(
      QPainter::Antialiasing); // Enable antialiasing to smooth out the lines
  m_chartView->setGeometry(
      ui->chartPlaceholder->geometry()); // Set geometry to match placeholder

  // Connect slider signals to slot methods
  connect(ui->frequencySlider, &QSlider::valueChanged, this,
          &Widget::on_frequencySlider_valueChanged);
  connect(ui->amplitudeSlider, &QSlider::valueChanged, this,
          &Widget::on_amplitudeSlider_valueChanged);

  // Set the tooltips for each slider
  ui->frequencySlider->setToolTip(
      "Adjusts the frequency of the signal between 20 Hz and 5000 Hz.");
  ui->amplitudeSlider->setToolTip(
      "Adjusts the amplitude of the signal between 0.0 and 1.0.");

  // Initialize sliders with default values
  ui->frequencySlider->setRange(20, 5000); // Frequency range
  ui->frequencySlider->setValue(1000);     // Default frequency
  ui->amplitudeSlider->setRange(
      0, 100); // Amplitude range 0-1 (represented as 0-100)
  ui->amplitudeSlider->setValue(50); // Default amplitude at 0.5

  updateGraph(); // Draw an initial graph based on default slider values
}

// Clean up UI resources
Widget::~Widget() { delete ui; }

// Update the chart based on the current slider values
void Widget::updateGraph() {
  double frequency = static_cast<double>(ui->frequencySlider->value());
  double amplitude = static_cast<double>(ui->amplitudeSlider->value()) / 100;

  QVector<QPointF> frequencyData;
  QVector<QPointF> amplitudeData;
  for (int i = 0; i < 360; ++i) {
    double radianValue = qDegreesToRadians(static_cast<double>(i));

    // Frequency visualization
    frequencyData.append(QPointF(i, qSin(frequency * radianValue)));

    // Amplitude visualization
    amplitudeData.append(QPointF(i, amplitude * qSin(radianValue)));
  }

  m_frequencySeries->replace(frequencyData);
  m_amplitudeSeries->replace(amplitudeData);
}

void Widget::on_frequencySlider_valueChanged(int value) {
  if (value < 20 || value > 5000) {
    ui->frequencySlider->setValue((value < 20) ? 20 : 5000);
    value = ui->frequencySlider->value();
  }
  ui->frequencyValue->setText(QString::number(value) + " Hz");
  updateGraph();
}

void Widget::on_amplitudeSlider_valueChanged(int value) {
  double normalizedAmplitude = static_cast<double>(value) / 100;
  if (normalizedAmplitude < 0.0 || normalizedAmplitude > 1.0) {
    int correctedValue = (normalizedAmplitude < 0.0) ? 0 : 100;
    ui->amplitudeSlider->setValue(correctedValue);
    normalizedAmplitude = static_cast<double>(correctedValue) / 100;
  }
  ui->amplitudeValue->setText(QString::number(normalizedAmplitude));
  updateGraph();
}
