#include "widget.h"
#include "./ui_widget.h"
#include "signalgenerator.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_generateButton_clicked()
{
    double frequency = ui->frequencyInput->text().toDouble();
    double amplitude = ui->amplitudeInput->text().toDouble();

    SignalGenerator generator;
    generator.setFrequency(frequency);
    generator.setAmplitude(amplitude);
    std::vector<double> signal = generator.generateSignal(44100);

    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(on_generateButton_clicked()));


}
void Widget::on_frequencySlider_valueChanged(int value)
{
    // Convert the slider's integer value to the desired frequency range. For example, 1-1000 Hz.
    double frequency = static_cast<double>(value);
    ui->frequencyInput->setText(QString::number(frequency));

    SignalGenerator generator;
    generator.setFrequency(frequency);
    generator.setAmplitude(ui->amplitudeInput->text().toDouble()); // Use existing amplitude value
    std::vector<double> signal = generator.generateSignal(44100);

    // Process/display the signal
    connect(ui->frequencySlider, SIGNAL(valueChanged(int)), this, SLOT(on_frequencySlider_valueChanged(int)));
}

void Widget::on_amplitudeSlider_valueChanged(int value)
{
    // Convert the slider's integer value to the desired amplitude range. For example, 0-1.
    double amplitude = static_cast<double>(value) / 100.0; // Convert to 0-1 range
    ui->amplitudeInput->setText(QString::number(amplitude));

    SignalGenerator generator;
    generator.setFrequency(ui->frequencyInput->text().toDouble()); // Use existing frequency value
    generator.setAmplitude(amplitude);
    std::vector<double> signal = generator.generateSignal(44100);

    // Process/display the signal
    connect(ui->amplitudeSlider, SIGNAL(valueChanged(int)), this, SLOT(on_amplitudeSlider_valueChanged(int)));
}
