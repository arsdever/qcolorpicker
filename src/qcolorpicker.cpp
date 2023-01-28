#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QLinearGradient>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QSlider>

#include "qcolorpicker/qcolorpicker.hpp"

QColorPicker::QColorPicker(QWidget* parent)
    : QDialog(parent)
{
    QBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QLabel* finalColorPreview = new QLabel(this);
    finalColorPreview->setMinimumSize(100, 100);
    mainLayout->addWidget(finalColorPreview);

    QBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addLayout(layout);

    QBoxLayout* controls = new QHBoxLayout();
    layout->addLayout(controls);

    QLabel* hexCodeLabel = new QLabel;
    controls->addWidget(hexCodeLabel);

    QGridLayout* colorSliders = new QGridLayout;

    QSlider* hueSlider = new QSlider(Qt::Horizontal);
    QSlider* saturationSlider = new QSlider(Qt::Horizontal);
    QSlider* brightnessSlider = new QSlider(Qt::Horizontal);
    QSlider* alphaSlider = new QSlider(Qt::Horizontal);
    QLabel* hueLabel = new QLabel;
    QLabel* saturationLabel = new QLabel;
    QLabel* brightnessLabel = new QLabel;
    QLabel* alphaLabel = new QLabel;

    auto updateColor = [ = ]() {
        QColor color;
        color.setHsv(
            hueSlider->value(),
            saturationSlider->value(),
            brightnessSlider->value(),
            alphaSlider->value()
        );
        finalColorPreview->setStyleSheet("background-color: " + color.name());
        hexCodeLabel->setText(color.name());
        _selectedColor = color;
    };

    connect(hueSlider, &QSlider::valueChanged, this, [ = ](int value) {
        hueLabel->setText(QString::number(value));
        updateColor();
    });
    connect(saturationSlider, &QSlider::valueChanged, this, [ = ](int value) {
        saturationLabel->setText(QString::number(value));
        updateColor();
    });
    connect(brightnessSlider, &QSlider::valueChanged, this, [ = ](int value) {
        brightnessLabel->setText(QString::number(value));
        updateColor();
    });
    connect(alphaSlider, &QSlider::valueChanged, this, [ = ](int value) {
        alphaLabel->setText(QString::number(value));
        updateColor();
    });

    hueLabel->setText(QString::number(hueSlider->value()));
    saturationLabel->setText(QString::number(saturationSlider->value()));
    brightnessLabel->setText(QString::number(brightnessSlider->value()));
    alphaLabel->setText(QString::number(alphaSlider->value()));

    hueSlider->setRange(0, 359);
    saturationSlider->setRange(0, 255);
    brightnessSlider->setRange(0, 255);
    alphaSlider->setRange(0, 255);

    hueSlider->setValue(180);
    saturationSlider->setValue(255);
    brightnessSlider->setValue(255);
    alphaSlider->setValue(255);

    colorSliders->addWidget(hueSlider, 0, 0);
    colorSliders->addWidget(hueLabel, 0, 1);
    colorSliders->addWidget(brightnessSlider, 2, 0);
    colorSliders->addWidget(brightnessLabel, 2, 1);
    colorSliders->addWidget(saturationSlider, 1, 0);
    colorSliders->addWidget(saturationLabel, 1, 1);
    colorSliders->addWidget(alphaSlider, 3, 0);
    colorSliders->addWidget(alphaLabel, 3, 1);

    layout->addLayout(colorSliders);

    QPushButton* selectButton = new QPushButton("Select");
    QPushButton* cancelButton = new QPushButton("Cancel");

    connect(selectButton, &QPushButton::clicked, this, &QColorPicker::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QColorPicker::reject);

    QBoxLayout* buttons = new QHBoxLayout();
    buttons->addWidget(selectButton);
    buttons->addWidget(cancelButton);
    layout->addLayout(buttons);

    updateColor();
}

QColorPicker::~QColorPicker() = default;

QColor QColorPicker::color() const { return _selectedColor; }
