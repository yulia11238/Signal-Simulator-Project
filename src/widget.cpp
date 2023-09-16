#include "widget.h"
#include "ui_widget.h"
#include "signalgenerator.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent) , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Set up the connections
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(on_generateButton_clicked()));
    connect(ui->frequencySlider, SIGNAL(valueChanged(int)), this, SLOT(on_frequencySlider_valueChanged(int)));
    connect(ui->amplitudeSlider, SIGNAL(valueChanged(int)), this, SLOT(on_amplitudeSlider_valueChanged(int)));
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

    // Display the generated signal in the QTextEdit
    QString displayText;
    for(double val : signal) {
        displayText.append(QString::number(val) + "\n");
    }
    ui->signalDisplay->setPlainText(displayText);
}

void Widget::on_frequencySlider_valueChanged(int value)
{
    // Convert the slider's integer value to the desired frequency range
    double frequency = static_cast<double>(value);
    ui->frequencyInput->setText(QString::number(frequency));

    SignalGenerator generator;
    generator.setFrequency(frequency);
    generator.setAmplitude(ui->amplitudeInput->text().toDouble()); // Use existing amplitude value
    std::vector<double> signal = generator.generateSignal(44100);

    // Display the generated signal in the QTextEdit
    QString displayText;
    for(double val : signal) {
        displayText.append(QString::number(val) + "\n");
    }
    ui->signalDisplay->setPlainText(displayText);
}

void Widget::on_amplitudeSlider_valueChanged(int value)
{
    // Convert the slider's integer value to the desired amplitude range
    double amplitude = static_cast<double>(value) / 100.0; // Convert to 0-1 range
    ui->amplitudeInput->setText(QString::number(amplitude));

    SignalGenerator generator;
    generator.setFrequency(ui->frequencyInput->text().toDouble()); // Use existing frequency value
    generator.setAmplitude(amplitude);
    std::vector<double> signal = generator.generateSignal(44100);

    // Display the generated signal in the QTextEdit
    QString displayText;
    for(double val : signal) {
        displayText.append(QString::number(val) + "\n");
    }
    ui->signalDisplay->setPlainText(displayText);
}
