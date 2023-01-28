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
};
