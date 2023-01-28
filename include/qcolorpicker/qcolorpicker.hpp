#pragma once

#include <QDialog>

class QColorPicker : public QDialog
{
public:
    /**
     * @brief Construct a new QColorPicker object
     *
     * @param parent the parent widget
     */
    explicit QColorPicker(QWidget* parent = nullptr);

    /**
     * @brief Destructor
     */
    ~QColorPicker();

    /**
     * @brief Get the color
     *
     * @return the color
     */
    QColor color() const;

private:
    QColor _selectedColor;
};
